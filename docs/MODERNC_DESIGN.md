# matiec Modern C++ 重构设计文档

> 版本: 1.0
> 日期: 2026-01-24
> 目标 C++ 标准: C++17 / C++20

---

## 目录

1. [概述](#1-概述)
2. [现状分析](#2-现状分析)
3. [重构目标与原则](#3-重构目标与原则)
4. [AST 与访问者模式重构](#4-ast-与访问者模式重构)
5. [内存管理现代化](#5-内存管理现代化)
6. [类型系统重构](#6-类型系统重构)
7. [错误处理统一](#7-错误处理统一)
8. [代码生成器重构](#8-代码生成器重构)
9. [符号表与作用域管理](#9-符号表与作用域管理)
10. [API 现代化](#10-api-现代化)
11. [迁移策略](#11-迁移策略)
12. [附录](#12-附录)

---

## 1. 概述

### 1.1 项目背景

matiec 是一个成熟的 IEC 61131-3 编译器，最初基于 2003-2011 年的 C++ 标准编写。随着 C++11/14/17/20 的发展，许多新特性可以显著提升代码的安全性、可维护性和性能。

### 1.2 文档目的

本文档详细描述将 matiec 代码库按照 Modern C++ 最佳实践进行重构的设计方案，包括：
- 架构改进设计
- 详细的代码模式转换
- 分阶段迁移计划
- 兼容性保证策略

### 1.3 适用范围

| 模块 | 当前状态 | 目标状态 |
|------|---------|---------|
| absyntax (AST) | 混合 C/C++ | Modern C++17 |
| stage1_2 (词法/语法) | Flex/Bison + 旧式 C++ | 保留生成器 + 现代接口 |
| stage3 (语义分析) | 旧式 C++ | Modern C++17 |
| stage4 (代码生成) | 旧式 C++ | Modern C++17 |
| util (工具库) | 部分现代化 | 完全 C++17 |
| include/matiec | 已现代化 | 保持/增强 |

---

## 2. 现状分析

### 2.1 代码库架构概览

```
┌─────────────────────────────────────────────────────────────┐
│                    matiec 编译器架构                        │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐     │
│  │  Stage 1/2  │ -> │   Stage 3   │ -> │   Stage 4   │     │
│  │ Flex+Bison  │    │  语义分析   │    │  代码生成   │     │
│  └──────┬──────┘    └──────┬──────┘    └──────┬──────┘     │
│         │                  │                  │             │
│         ▼                  ▼                  ▼             │
│  ┌──────────────────────────────────────────────────┐      │
│  │                 AST (symbol_c)                   │      │
│  │            ~500+ 节点类型 (生成代码)              │      │
│  └──────────────────────────────────────────────────┘      │
│         ▲                  ▲                  ▲             │
│         │                  │                  │             │
│  ┌──────┴──────┐    ┌──────┴──────┐    ┌──────┴──────┐     │
│  │   visitor   │    │  symtable   │    │   error     │     │
│  │  遍历模式   │    │   符号表    │    │   报告      │     │
│  └─────────────┘    └─────────────┘    └─────────────┘     │
└─────────────────────────────────────────────────────────────┘
```

### 2.2 现有代码特征分析

#### 2.2.1 已现代化的部分 (✓)

| 文件/模块 | 现代特性 |
|-----------|---------|
| `include/matiec/error.hpp` | `std::optional`, `std::unique_ptr`, `[[nodiscard]]`, `constexpr` |
| `include/matiec/string_utils.hpp` | `std::string_view`, `[[nodiscard]]`, `noexcept` |
| `util/symtable.hh` | `std::unique_ptr`, `std::string_view`, 移动语义 |
| `absyntax/absyntax.hh` | `std::string_view`, `token_string` 封装 |
| `src/matiec_lib.cc` | RAII, 现代错误处理 |

#### 2.2.2 需要现代化的部分 (✗)

**1. 原始指针和手动内存管理**
```cpp
// 当前代码 (absyntax.hh:214)
symbol_c *parent;           // 原始指针
symbol_c *datatype;         // 原始指针
std::vector<symbol_c *> candidate_datatypes;  // 原始指针容器

// fill_candidate_datatypes.hh:59
search_var_instance_decl_c *search_var_instance_decl;  // 原始指针
```

**2. 返回 `void*` 的访问者模式**
```cpp
// visitor.hh:81
class visitor_c {
  public:
    virtual void *visit(symbol_c *symbol) = 0;  // 类型不安全
    // ... 500+ 个类似方法
};
```

**3. 全局状态和 extern 变量**
```cpp
// main.hh 中的全局配置
extern runtime_options_t runtime_options;

// stage1_2 中的全局状态
extern symbol_c *tree_root;
```

**4. C 风格字符串处理**
```cpp
// 部分代码仍使用
const char *first_file;
const char *last_file;
```

**5. 宏驱动的 AST 节点生成**
```cpp
// absyntax.hh:406
#define SYM_LIST(class_name_c, ...)
#define SYM_TOKEN(class_name_c, ...)
#define SYM_REF0(class_name_c, ...)
// ... 等宏定义生成 500+ 个节点类
```

### 2.3 代码统计

| 类别 | 行数 | 备注 |
|------|------|------|
| 手动编写代码 | ~40,000 | 核心逻辑 |
| 生成代码 | ~20,000 | AST 节点、visitor 方法 |
| 原始指针使用 | ~2,500 处 | 需要评估和迁移 |
| `void*` 返回值 | ~500+ 方法 | visitor 模式 |

---

## 3. 重构目标与原则

### 3.1 核心目标

1. **类型安全**: 消除 `void*` 返回值，使用强类型
2. **内存安全**: 用智能指针替代原始指针，RAII 管理资源
3. **值语义**: 优先使用值类型，减少堆分配
4. **不可变性**: 明确 const 语义，减少可变状态
5. **错误处理**: 统一使用结构化错误系统

### 3.2 设计原则

```
┌─────────────────────────────────────────────────────────┐
│                    设计原则金字塔                       │
├─────────────────────────────────────────────────────────┤
│                                                         │
│                    ┌─────────┐                          │
│                    │  YAGNI  │  不过度设计              │
│                    └────┬────┘                          │
│                 ┌───────┴───────┐                       │
│                 │     KISS      │  保持简单             │
│                 └───────┬───────┘                       │
│             ┌───────────┴───────────┐                   │
│             │         DRY           │  消除重复         │
│             └───────────┬───────────┘                   │
│         ┌───────────────┴───────────────┐               │
│         │          SOLID 原则           │               │
│         │  S: 单一职责  O: 开闭原则     │               │
│         │  L: 里氏替换  I: 接口隔离     │               │
│         │  D: 依赖倒置                  │               │
│         └───────────────────────────────┘               │
└─────────────────────────────────────────────────────────┘
```

### 3.3 兼容性约束

| 约束 | 说明 |
|------|------|
| C API 兼容 | `matiec.h` 接口保持不变 |
| Flex/Bison 兼容 | 生成器接口保持兼容 |
| 渐进式迁移 | 支持新旧代码共存 |
| 编译器支持 | GCC 8+, Clang 7+, MSVC 2019+ |

---

## 4. AST 与访问者模式重构

### 4.1 当前架构问题

```cpp
// 问题 1: void* 返回值丢失类型信息
class visitor_c {
    virtual void *visit(program_declaration_c *symbol) = 0;
};

// 问题 2: 手动类型转换易出错
void *result = symbol->accept(*visitor);
program_declaration_c *prog = static_cast<program_declaration_c*>(result);

// 问题 3: 无法表达不同访问者的返回类型
class type_checker : public visitor_c { /* 返回 bool? symbol_c*? */ };
class code_generator : public visitor_c { /* 返回 string? void? */ };
```

### 4.2 目标架构: 类型安全的访问者

#### 4.2.1 引入 VisitorResult 变体类型

```cpp
// include/matiec/ast/visitor_result.hpp

#ifndef MATIEC_AST_VISITOR_RESULT_HPP
#define MATIEC_AST_VISITOR_RESULT_HPP

#include <variant>
#include <optional>
#include <string>
#include <memory>

namespace matiec::ast {

// 前向声明
class Symbol;

/**
 * @brief 访问者返回值类型
 *
 * 使用 std::variant 统一不同访问者的返回类型，
 * 提供类型安全的返回值处理。
 */
using VisitorResult = std::variant<
    std::monostate,                      // 无返回值 (void)
    bool,                                // 布尔结果 (类型检查等)
    int64_t,                             // 整数结果 (常量折叠)
    double,                              // 浮点结果 (常量折叠)
    std::string,                         // 字符串结果 (代码生成)
    Symbol*,                             // 符号引用 (AST 转换)
    std::unique_ptr<Symbol>,             // 符号所有权 (AST 构建)
    std::vector<Symbol*>                 // 符号列表 (收集结果)
>;

/**
 * @brief 类型安全的结果访问
 */
template<typename T>
[[nodiscard]] inline std::optional<T> get_result(const VisitorResult& result) {
    if (auto* value = std::get_if<T>(&result)) {
        return *value;
    }
    return std::nullopt;
}

/**
 * @brief 检查结果是否为特定类型
 */
template<typename T>
[[nodiscard]] inline bool holds_result(const VisitorResult& result) {
    return std::holds_alternative<T>(result);
}

/**
 * @brief 判断结果是否为"空" (monostate 或 nullptr)
 */
[[nodiscard]] inline bool is_empty(const VisitorResult& result) {
    if (std::holds_alternative<std::monostate>(result)) return true;
    if (auto* ptr = std::get_if<Symbol*>(&result)) return *ptr == nullptr;
    return false;
}

} // namespace matiec::ast

#endif // MATIEC_AST_VISITOR_RESULT_HPP
```

#### 4.2.2 现代化的 Visitor 基类

```cpp
// include/matiec/ast/visitor.hpp

#ifndef MATIEC_AST_VISITOR_HPP
#define MATIEC_AST_VISITOR_HPP

#include "visitor_result.hpp"
#include "symbol_fwd.hpp"  // 前向声明所有 AST 节点

namespace matiec::ast {

/**
 * @brief 现代化的访问者接口
 *
 * 关键改进:
 * 1. 返回 VisitorResult 而非 void*
 * 2. 使用 const 引用参数
 * 3. [[nodiscard]] 标记
 * 4. 提供默认实现选项
 */
class Visitor {
public:
    virtual ~Visitor() = default;

    // 禁用复制，允许移动
    Visitor(const Visitor&) = delete;
    Visitor& operator=(const Visitor&) = delete;
    Visitor(Visitor&&) = default;
    Visitor& operator=(Visitor&&) = default;

protected:
    Visitor() = default;

public:
    // ========== 核心访问方法 ==========

    // 基类节点 - 默认实现可遍历子节点
    [[nodiscard]] virtual VisitorResult visit(Symbol& symbol);
    [[nodiscard]] virtual VisitorResult visit(Token& symbol);
    [[nodiscard]] virtual VisitorResult visit(List& symbol);

    // ========== 生成的方法声明 ==========
    // 由 gen_absyntax.py 生成，示例:

    [[nodiscard]] virtual VisitorResult visit(ProgramDeclaration& symbol);
    [[nodiscard]] virtual VisitorResult visit(FunctionDeclaration& symbol);
    [[nodiscard]] virtual VisitorResult visit(FunctionBlockDeclaration& symbol);
    // ... 其他 500+ 节点类型

    // 包含生成的声明
    #include "generated/visitor_methods_decl.gen.hpp"
};

/**
 * @brief 空访问者 - 所有方法返回空结果
 */
class NullVisitor : public Visitor {
public:
    // 包含生成的默认实现
    #include "generated/visitor_methods_null.gen.hpp"
};

/**
 * @brief 迭代访问者 - 自动遍历所有子节点
 */
class IteratorVisitor : public Visitor {
protected:
    VisitorResult visitList(List& list);

public:
    // 包含生成的迭代实现
    #include "generated/visitor_methods_iterator.gen.hpp"
};

/**
 * @brief 搜索访问者 - 遍历直到找到非空结果
 */
class SearchVisitor : public Visitor {
protected:
    VisitorResult visitList(List& list);

public:
    // 包含生成的搜索实现
    #include "generated/visitor_methods_search.gen.hpp"
};

} // namespace matiec::ast

#endif // MATIEC_AST_VISITOR_HPP
```

### 4.3 AST 节点现代化

#### 4.3.1 基类 Symbol 重构

```cpp
// include/matiec/ast/symbol.hpp

#ifndef MATIEC_AST_SYMBOL_HPP
#define MATIEC_AST_SYMBOL_HPP

#include <string>
#include <string_view>
#include <vector>
#include <optional>
#include <memory>
#include <cstdint>
#include "visitor_result.hpp"
#include "source_location.hpp"
#include "const_value.hpp"

namespace matiec::ast {

// 前向声明
class Visitor;
class Token;

/**
 * @brief 源码位置信息 (值类型)
 */
struct SourceRange {
    SourceLocation start;
    SourceLocation end;

    [[nodiscard]] bool isValid() const noexcept {
        return start.isValid();
    }
};

/**
 * @brief AST 节点基类
 *
 * 设计决策:
 * - 使用非拥有指针 (Symbol*) 作为 parent，因为生命周期由 AST 整体管理
 * - 子节点关系在派生类中定义
 * - 注解数据作为值类型成员
 */
class Symbol {
public:
    // ========== 生命周期 ==========

    Symbol() = default;
    explicit Symbol(SourceRange range) : range_(std::move(range)) {}

    virtual ~Symbol() = default;

    // 禁用复制 (AST 节点通常不应被复制)
    Symbol(const Symbol&) = delete;
    Symbol& operator=(const Symbol&) = delete;

    // 允许移动
    Symbol(Symbol&&) = default;
    Symbol& operator=(Symbol&&) = default;

    // ========== 访问者模式 ==========

    /**
     * @brief 接受访问者
     * @return 访问结果
     */
    [[nodiscard]] virtual VisitorResult accept(Visitor& visitor) = 0;

    /**
     * @brief 获取节点类型名称 (用于调试)
     */
    [[nodiscard]] virtual std::string_view typeName() const noexcept = 0;

    // ========== 位置信息 ==========

    [[nodiscard]] const SourceRange& range() const noexcept { return range_; }
    void setRange(SourceRange range) noexcept { range_ = std::move(range); }

    // ========== 树结构 ==========

    /**
     * @brief 获取父节点 (非拥有指针)
     */
    [[nodiscard]] Symbol* parent() const noexcept { return parent_; }
    void setParent(Symbol* p) noexcept { parent_ = p; }

    /**
     * @brief 获取关联的标识符 token (如果有)
     */
    [[nodiscard]] Token* identifierToken() const noexcept { return identifier_token_; }
    void setIdentifierToken(Token* t) noexcept { identifier_token_ = t; }

    // ========== Stage 3 注解 ==========

    /**
     * @brief 候选数据类型列表
     */
    std::vector<Symbol*> candidateDatatypes;

    /**
     * @brief 确定的数据类型
     */
    Symbol* datatype = nullptr;

    /**
     * @brief 作用域 (所在的 POU)
     */
    Symbol* scope = nullptr;

    /**
     * @brief 常量折叠结果
     */
    ConstValue constValue;

private:
    SourceRange range_;
    Symbol* parent_ = nullptr;
    Token* identifier_token_ = nullptr;
};

/**
 * @brief Token 节点 - 表示词法单元
 */
class Token : public Symbol {
public:
    Token() = default;
    explicit Token(std::string value, SourceRange range = {})
        : Symbol(std::move(range)), value_(std::move(value)) {}

    [[nodiscard]] VisitorResult accept(Visitor& visitor) override;
    [[nodiscard]] std::string_view typeName() const noexcept override { return "Token"; }

    // ========== 值访问 ==========

    [[nodiscard]] std::string_view value() const noexcept { return value_; }
    [[nodiscard]] const char* c_str() const noexcept { return value_.c_str(); }

    void setValue(std::string v) { value_ = std::move(v); }

private:
    std::string value_;
};

/**
 * @brief List 节点 - 表示节点列表
 */
class List : public Symbol {
public:
    using iterator = std::vector<std::unique_ptr<Symbol>>::iterator;
    using const_iterator = std::vector<std::unique_ptr<Symbol>>::const_iterator;

    List() = default;
    explicit List(SourceRange range) : Symbol(std::move(range)) {}

    [[nodiscard]] VisitorResult accept(Visitor& visitor) override;
    [[nodiscard]] std::string_view typeName() const noexcept override { return "List"; }

    // ========== 元素访问 ==========

    [[nodiscard]] size_t size() const noexcept { return elements_.size(); }
    [[nodiscard]] bool empty() const noexcept { return elements_.empty(); }

    [[nodiscard]] Symbol* operator[](size_t index) const {
        return elements_[index].get();
    }

    [[nodiscard]] Symbol* at(size_t index) const {
        return elements_.at(index).get();
    }

    // ========== 元素修改 ==========

    void add(std::unique_ptr<Symbol> elem) {
        if (elem) elem->setParent(this);
        elements_.push_back(std::move(elem));
    }

    template<typename T, typename... Args>
    T* emplace(Args&&... args) {
        auto elem = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = elem.get();
        add(std::move(elem));
        return ptr;
    }

    void insert(size_t pos, std::unique_ptr<Symbol> elem) {
        if (elem) elem->setParent(this);
        elements_.insert(elements_.begin() + pos, std::move(elem));
    }

    std::unique_ptr<Symbol> remove(size_t pos) {
        auto elem = std::move(elements_[pos]);
        elements_.erase(elements_.begin() + pos);
        if (elem) elem->setParent(nullptr);
        return elem;
    }

    void clear() { elements_.clear(); }

    // ========== 迭代器 ==========

    [[nodiscard]] iterator begin() noexcept { return elements_.begin(); }
    [[nodiscard]] iterator end() noexcept { return elements_.end(); }
    [[nodiscard]] const_iterator begin() const noexcept { return elements_.begin(); }
    [[nodiscard]] const_iterator end() const noexcept { return elements_.end(); }
    [[nodiscard]] const_iterator cbegin() const noexcept { return elements_.cbegin(); }
    [[nodiscard]] const_iterator cend() const noexcept { return elements_.cend(); }

    // ========== 查找 ==========

    /**
     * @brief 按标识符查找元素
     */
    [[nodiscard]] Symbol* findByIdentifier(std::string_view name) const;

private:
    std::vector<std::unique_ptr<Symbol>> elements_;
};

} // namespace matiec::ast

#endif // MATIEC_AST_SYMBOL_HPP
```

#### 4.3.2 具体节点类型示例

```cpp
// include/matiec/ast/declarations.hpp

#ifndef MATIEC_AST_DECLARATIONS_HPP
#define MATIEC_AST_DECLARATIONS_HPP

#include "symbol.hpp"

namespace matiec::ast {

/**
 * @brief 程序声明节点
 *
 * 对应 IEC 61131-3:
 *   PROGRAM program_name
 *     var_declarations
 *     function_block_body
 *   END_PROGRAM
 */
class ProgramDeclaration final : public Symbol {
public:
    ProgramDeclaration() = default;

    ProgramDeclaration(
        std::unique_ptr<Token> name,
        std::unique_ptr<Symbol> varDeclarations,
        std::unique_ptr<Symbol> body,
        SourceRange range = {}
    ) : Symbol(std::move(range)),
        name_(std::move(name)),
        varDeclarations_(std::move(varDeclarations)),
        body_(std::move(body))
    {
        if (name_) name_->setParent(this);
        if (varDeclarations_) varDeclarations_->setParent(this);
        if (body_) body_->setParent(this);
        setIdentifierToken(name_.get());
    }

    [[nodiscard]] VisitorResult accept(Visitor& visitor) override;
    [[nodiscard]] std::string_view typeName() const noexcept override {
        return "ProgramDeclaration";
    }

    // ========== 子节点访问 ==========

    [[nodiscard]] Token* name() const noexcept { return name_.get(); }
    [[nodiscard]] Symbol* varDeclarations() const noexcept { return varDeclarations_.get(); }
    [[nodiscard]] Symbol* body() const noexcept { return body_.get(); }

    // ========== 子节点修改 ==========

    void setName(std::unique_ptr<Token> n) {
        name_ = std::move(n);
        if (name_) name_->setParent(this);
        setIdentifierToken(name_.get());
    }

    void setVarDeclarations(std::unique_ptr<Symbol> v) {
        varDeclarations_ = std::move(v);
        if (varDeclarations_) varDeclarations_->setParent(this);
    }

    void setBody(std::unique_ptr<Symbol> b) {
        body_ = std::move(b);
        if (body_) body_->setParent(this);
    }

private:
    std::unique_ptr<Token> name_;
    std::unique_ptr<Symbol> varDeclarations_;
    std::unique_ptr<Symbol> body_;
};

/**
 * @brief 函数声明节点
 */
class FunctionDeclaration final : public Symbol {
public:
    FunctionDeclaration() = default;

    [[nodiscard]] VisitorResult accept(Visitor& visitor) override;
    [[nodiscard]] std::string_view typeName() const noexcept override {
        return "FunctionDeclaration";
    }

    // ========== 子节点 ==========

    [[nodiscard]] Token* name() const noexcept { return name_.get(); }
    [[nodiscard]] Symbol* returnType() const noexcept { return returnType_.get(); }
    [[nodiscard]] Symbol* varDeclarations() const noexcept { return varDeclarations_.get(); }
    [[nodiscard]] Symbol* body() const noexcept { return body_.get(); }

private:
    std::unique_ptr<Token> name_;
    std::unique_ptr<Symbol> returnType_;
    std::unique_ptr<Symbol> varDeclarations_;
    std::unique_ptr<Symbol> body_;
};

/**
 * @brief 功能块声明节点
 */
class FunctionBlockDeclaration final : public Symbol {
public:
    FunctionBlockDeclaration() = default;

    [[nodiscard]] VisitorResult accept(Visitor& visitor) override;
    [[nodiscard]] std::string_view typeName() const noexcept override {
        return "FunctionBlockDeclaration";
    }

    [[nodiscard]] Token* name() const noexcept { return name_.get(); }
    [[nodiscard]] Symbol* varDeclarations() const noexcept { return varDeclarations_.get(); }
    [[nodiscard]] Symbol* body() const noexcept { return body_.get(); }

private:
    std::unique_ptr<Token> name_;
    std::unique_ptr<Symbol> varDeclarations_;
    std::unique_ptr<Symbol> body_;
};

} // namespace matiec::ast

#endif // MATIEC_AST_DECLARATIONS_HPP
```

### 4.4 代码生成器改造

更新 `gen_absyntax.py` 以生成现代化的节点类:

```python
# gen_absyntax.py 改进 (伪代码)

def generate_node_class(node_def):
    """生成现代化的节点类"""
    return f'''
class {node_def.name} final : public Symbol {{
public:
    {node_def.name}() = default;

    // 构造函数
    {generate_constructor(node_def)}

    // 访问者模式
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {{
        return visitor.visit(*this);
    }}

    [[nodiscard]] std::string_view typeName() const noexcept override {{
        return "{node_def.name}";
    }}

    // 子节点访问器
    {generate_accessors(node_def)}

private:
    {generate_members(node_def)}
}};
'''
```

### 4.5 迁移适配层（Phase 6 已移除）

为平滑迁移曾引入 `legacy_compat.hpp` 适配层（桥接旧式 `void*` 访问者）。
在 Phase 6 中该适配层已移除，代码库仅保留现代 Visitor 接口。
如需兼容旧代码，请在下游工程中自行实现桥接。

---

## 5. 内存管理现代化

### 5.1 当前问题

```cpp
// 问题 1: 原始指针，所有权不清晰
symbol_c *tree_root;  // 谁负责删除？

// 问题 2: 手动内存池
void* symbol_c::operator new(std::size_t size);
void symbol_c::operator delete(void* ptr);

// 问题 3: 手动清理
void ast_delete(symbol_c* root);
void cstr_pool_clear();
```

### 5.2 智能指针策略

```
┌─────────────────────────────────────────────────────────────┐
│                    所有权模型                               │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ┌─────────────────────────────────────────────────────┐   │
│  │             unique_ptr<Symbol>                      │   │
│  │  ┌─────────────────────────────────────────────┐   │   │
│  │  │  父节点拥有子节点                           │   │   │
│  │  │  List 拥有其元素                           │   │   │
│  │  │  CompilationUnit 拥有 AST 根               │   │   │
│  │  └─────────────────────────────────────────────┘   │   │
│  └─────────────────────────────────────────────────────┘   │
│                                                             │
│  ┌─────────────────────────────────────────────────────┐   │
│  │             Symbol* (非拥有指针)                    │   │
│  │  ┌─────────────────────────────────────────────┐   │   │
│  │  │  parent 指针 (子指向父)                     │   │   │
│  │  │  datatype 注解 (指向类型定义)               │   │   │
│  │  │  scope 注解 (指向作用域)                    │   │   │
│  │  │  candidate_datatypes 元素                   │   │   │
│  │  └─────────────────────────────────────────────┘   │   │
│  └─────────────────────────────────────────────────────┘   │
│                                                             │
│  ┌─────────────────────────────────────────────────────┐   │
│  │             shared_ptr<T> (极少使用)                │   │
│  │  ┌─────────────────────────────────────────────┐   │   │
│  │  │  跨编译单元共享的类型定义                   │   │   │
│  │  │  标准库中的内建类型                         │   │   │
│  │  └─────────────────────────────────────────────┘   │   │
│  └─────────────────────────────────────────────────────┘   │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### 5.3 编译单元封装

```cpp
// include/matiec/compiler/compilation_unit.hpp

#ifndef MATIEC_COMPILER_COMPILATION_UNIT_HPP
#define MATIEC_COMPILER_COMPILATION_UNIT_HPP

#include "../ast/symbol.hpp"
#include "../error.hpp"
#include <memory>
#include <string>
#include <vector>

namespace matiec::compiler {

/**
 * @brief 编译单元 - 管理单次编译的所有资源
 *
 * 设计原则:
 * - RAII: 析构时自动清理所有资源
 * - 单一所有权: 拥有 AST 和所有关联数据
 * - 线程安全: 每个编译在独立的 CompilationUnit 中
 */
class CompilationUnit {
public:
    CompilationUnit() = default;
    ~CompilationUnit() = default;

    // 不可复制
    CompilationUnit(const CompilationUnit&) = delete;
    CompilationUnit& operator=(const CompilationUnit&) = delete;

    // 可移动
    CompilationUnit(CompilationUnit&&) = default;
    CompilationUnit& operator=(CompilationUnit&&) = default;

    // ========== AST 管理 ==========

    /**
     * @brief 设置 AST 根节点 (转移所有权)
     */
    void setAstRoot(std::unique_ptr<ast::Symbol> root) {
        astRoot_ = std::move(root);
    }

    /**
     * @brief 获取 AST 根节点 (非拥有指针)
     */
    [[nodiscard]] ast::Symbol* astRoot() const noexcept {
        return astRoot_.get();
    }

    /**
     * @brief 释放 AST 所有权
     */
    [[nodiscard]] std::unique_ptr<ast::Symbol> releaseAst() {
        return std::move(astRoot_);
    }

    // ========== 错误管理 ==========

    [[nodiscard]] ErrorReporter& errors() noexcept { return errors_; }
    [[nodiscard]] const ErrorReporter& errors() const noexcept { return errors_; }

    // ========== 源文件信息 ==========

    void setSourceFile(std::string path) { sourceFile_ = std::move(path); }
    [[nodiscard]] const std::string& sourceFile() const noexcept { return sourceFile_; }

    // ========== 编译状态 ==========

    [[nodiscard]] bool isValid() const noexcept {
        return astRoot_ != nullptr && !errors_.hasErrors();
    }

private:
    std::unique_ptr<ast::Symbol> astRoot_;
    ErrorReporter errors_;
    std::string sourceFile_;
};

} // namespace matiec::compiler

#endif // MATIEC_COMPILER_COMPILATION_UNIT_HPP
```

### 5.4 字符串池现代化

```cpp
// include/matiec/util/string_pool.hpp

#ifndef MATIEC_UTIL_STRING_POOL_HPP
#define MATIEC_UTIL_STRING_POOL_HPP

#include <string>
#include <string_view>
#include <unordered_set>
#include <memory>

namespace matiec::util {

/**
 * @brief 字符串池 - 去重存储字符串
 *
 * 用于词法分析阶段的标识符和字面量去重。
 * 返回的 string_view 在池存在期间有效。
 */
class StringPool {
public:
    StringPool() = default;
    ~StringPool() = default;

    // 不可复制
    StringPool(const StringPool&) = delete;
    StringPool& operator=(const StringPool&) = delete;

    // 可移动
    StringPool(StringPool&&) = default;
    StringPool& operator=(StringPool&&) = default;

    /**
     * @brief 添加或查找字符串
     * @return 池中字符串的 string_view (生命周期 = 池的生命周期)
     */
    [[nodiscard]] std::string_view intern(std::string_view s) {
        auto [it, inserted] = pool_.emplace(s);
        return *it;
    }

    /**
     * @brief 获取 C 风格字符串 (兼容旧代码)
     */
    [[nodiscard]] const char* intern_c(std::string_view s) {
        return intern(s).data();
    }

    /**
     * @brief 清空池
     */
    void clear() noexcept {
        pool_.clear();
    }

    /**
     * @brief 获取池中字符串数量
     */
    [[nodiscard]] size_t size() const noexcept {
        return pool_.size();
    }

private:
    std::unordered_set<std::string> pool_;
};

} // namespace matiec::util

#endif // MATIEC_UTIL_STRING_POOL_HPP
```

---

## 6. 类型系统重构

### 6.1 当前类型表示

```cpp
// 当前: 使用 AST 节点表示类型
symbol_c *datatype;  // 指向类型定义节点

// 判断类型需要遍历:
bool is_integer_type = get_datatype_info_c::is_ANY_INT(datatype);
```

### 6.2 独立的类型系统

```cpp
// include/matiec/types/type.hpp

#ifndef MATIEC_TYPES_TYPE_HPP
#define MATIEC_TYPES_TYPE_HPP

#include <string>
#include <string_view>
#include <memory>
#include <vector>
#include <optional>
#include <variant>

namespace matiec::types {

// 前向声明
class Type;
class ElementaryType;
class DerivedType;
class ArrayType;
class StructType;
class FunctionBlockType;

/**
 * @brief 类型类别枚举
 */
enum class TypeCategory : uint8_t {
    // 基本类型
    Bool,
    Byte, Word, DWord, LWord,
    SInt, Int, DInt, LInt,
    USInt, UInt, UDInt, ULInt,
    Real, LReal,
    Time, Date, TimeOfDay, DateAndTime,
    String, WString,

    // 派生类型
    Array,
    Struct,
    Enum,
    Subrange,
    Ref,

    // POU 类型
    Function,
    FunctionBlock,
    Program,

    // 特殊
    Any,
    Invalid
};

/**
 * @brief 类型基类
 */
class Type {
public:
    virtual ~Type() = default;

    [[nodiscard]] virtual TypeCategory category() const noexcept = 0;
    [[nodiscard]] virtual std::string_view name() const noexcept = 0;
    [[nodiscard]] virtual size_t sizeInBits() const noexcept = 0;

    // 类型查询
    [[nodiscard]] bool isElementary() const noexcept;
    [[nodiscard]] bool isNumeric() const noexcept;
    [[nodiscard]] bool isInteger() const noexcept;
    [[nodiscard]] bool isReal() const noexcept;
    [[nodiscard]] bool isBitString() const noexcept;
    [[nodiscard]] bool isString() const noexcept;
    [[nodiscard]] bool isTime() const noexcept;
    [[nodiscard]] bool isDate() const noexcept;
    [[nodiscard]] bool isArray() const noexcept;
    [[nodiscard]] bool isStruct() const noexcept;
    [[nodiscard]] bool isRef() const noexcept;

    // 类型转换
    [[nodiscard]] virtual const ElementaryType* asElementary() const noexcept { return nullptr; }
    [[nodiscard]] virtual const ArrayType* asArray() const noexcept { return nullptr; }
    [[nodiscard]] virtual const StructType* asStruct() const noexcept { return nullptr; }

    // 类型兼容性
    [[nodiscard]] virtual bool isCompatibleWith(const Type& other) const noexcept;
    [[nodiscard]] virtual bool isAssignableTo(const Type& other) const noexcept;

    // 打印
    [[nodiscard]] virtual std::string toString() const;

protected:
    Type() = default;
};

/**
 * @brief 基本类型
 */
class ElementaryType final : public Type {
public:
    explicit ElementaryType(TypeCategory cat) : category_(cat) {}

    [[nodiscard]] TypeCategory category() const noexcept override { return category_; }
    [[nodiscard]] std::string_view name() const noexcept override;
    [[nodiscard]] size_t sizeInBits() const noexcept override;

    [[nodiscard]] const ElementaryType* asElementary() const noexcept override { return this; }

private:
    TypeCategory category_;
};

/**
 * @brief 数组类型
 */
class ArrayType final : public Type {
public:
    struct Dimension {
        int64_t lower;
        int64_t upper;

        [[nodiscard]] size_t size() const noexcept {
            return static_cast<size_t>(upper - lower + 1);
        }
    };

    ArrayType(std::shared_ptr<const Type> elementType, std::vector<Dimension> dims)
        : elementType_(std::move(elementType)), dimensions_(std::move(dims)) {}

    [[nodiscard]] TypeCategory category() const noexcept override { return TypeCategory::Array; }
    [[nodiscard]] std::string_view name() const noexcept override { return "ARRAY"; }
    [[nodiscard]] size_t sizeInBits() const noexcept override;

    [[nodiscard]] const ArrayType* asArray() const noexcept override { return this; }

    [[nodiscard]] const Type& elementType() const noexcept { return *elementType_; }
    [[nodiscard]] const std::vector<Dimension>& dimensions() const noexcept { return dimensions_; }
    [[nodiscard]] size_t rank() const noexcept { return dimensions_.size(); }

private:
    std::shared_ptr<const Type> elementType_;
    std::vector<Dimension> dimensions_;
};

/**
 * @brief 结构体类型
 */
class StructType final : public Type {
public:
    struct Field {
        std::string name;
        std::shared_ptr<const Type> type;
        std::optional<std::string> initialValue;
    };

    StructType(std::string name, std::vector<Field> fields)
        : name_(std::move(name)), fields_(std::move(fields)) {}

    [[nodiscard]] TypeCategory category() const noexcept override { return TypeCategory::Struct; }
    [[nodiscard]] std::string_view name() const noexcept override { return name_; }
    [[nodiscard]] size_t sizeInBits() const noexcept override;

    [[nodiscard]] const StructType* asStruct() const noexcept override { return this; }

    [[nodiscard]] const std::vector<Field>& fields() const noexcept { return fields_; }
    [[nodiscard]] const Field* findField(std::string_view name) const noexcept;

private:
    std::string name_;
    std::vector<Field> fields_;
};

/**
 * @brief 枚举类型
 */
class EnumType final : public Type {
public:
    struct Enumerator {
        std::string name;
        std::optional<int64_t> value;
    };

    EnumType(std::string name, std::vector<Enumerator> enumerators)
        : name_(std::move(name)), enumerators_(std::move(enumerators)) {}

    [[nodiscard]] TypeCategory category() const noexcept override { return TypeCategory::Enum; }
    [[nodiscard]] std::string_view name() const noexcept override { return name_; }
    [[nodiscard]] size_t sizeInBits() const noexcept override { return 32; } // 通常

    [[nodiscard]] const std::vector<Enumerator>& enumerators() const noexcept { return enumerators_; }
    [[nodiscard]] bool hasEnumerator(std::string_view name) const noexcept;

private:
    std::string name_;
    std::vector<Enumerator> enumerators_;
};

/**
 * @brief 类型注册表 - 管理所有类型定义
 */
class TypeRegistry {
public:
    TypeRegistry();

    // 获取内建类型
    [[nodiscard]] std::shared_ptr<const Type> getBool() const noexcept;
    [[nodiscard]] std::shared_ptr<const Type> getInt() const noexcept;
    [[nodiscard]] std::shared_ptr<const Type> getDInt() const noexcept;
    [[nodiscard]] std::shared_ptr<const Type> getReal() const noexcept;
    [[nodiscard]] std::shared_ptr<const Type> getString() const noexcept;
    [[nodiscard]] std::shared_ptr<const Type> getTime() const noexcept;

    // 按名称查找
    [[nodiscard]] std::shared_ptr<const Type> findType(std::string_view name) const;

    // 注册用户定义类型
    void registerType(std::string name, std::shared_ptr<Type> type);

    // 创建数组类型
    [[nodiscard]] std::shared_ptr<const ArrayType> createArrayType(
        std::shared_ptr<const Type> elementType,
        std::vector<ArrayType::Dimension> dims
    );

    // 创建结构体类型
    [[nodiscard]] std::shared_ptr<const StructType> createStructType(
        std::string name,
        std::vector<StructType::Field> fields
    );

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace matiec::types

#endif // MATIEC_TYPES_TYPE_HPP
```

### 6.3 类型推断器

```cpp
// include/matiec/types/type_inferrer.hpp

#ifndef MATIEC_TYPES_TYPE_INFERRER_HPP
#define MATIEC_TYPES_TYPE_INFERRER_HPP

#include "type.hpp"
#include "../ast/visitor.hpp"

namespace matiec::types {

/**
 * @brief 类型推断器 - 为 AST 节点推断类型
 */
class TypeInferrer : public ast::IteratorVisitor {
public:
    explicit TypeInferrer(TypeRegistry& registry) : registry_(registry) {}

    /**
     * @brief 推断表达式类型
     */
    [[nodiscard]] std::shared_ptr<const Type> inferType(ast::Symbol& expr);

    /**
     * @brief 获取候选类型列表
     */
    [[nodiscard]] std::vector<std::shared_ptr<const Type>>
    getCandidateTypes(ast::Symbol& expr);

    // 访问者方法
    ast::VisitorResult visit(ast::IntegerLiteral& symbol) override;
    ast::VisitorResult visit(ast::RealLiteral& symbol) override;
    ast::VisitorResult visit(ast::StringLiteral& symbol) override;
    ast::VisitorResult visit(ast::BooleanLiteral& symbol) override;
    ast::VisitorResult visit(ast::SymbolicVariable& symbol) override;
    ast::VisitorResult visit(ast::AddExpression& symbol) override;
    // ... 其他节点

private:
    TypeRegistry& registry_;
};

} // namespace matiec::types

#endif // MATIEC_TYPES_TYPE_INFERRER_HPP
```

---

## 7. 错误处理统一

### 7.1 当前状态

error.hpp 已经提供了良好的现代错误处理基础设施。需要将其推广到所有模块。

### 7.2 集成策略

```cpp
// include/matiec/diagnostics/diagnostic.hpp

#ifndef MATIEC_DIAGNOSTICS_DIAGNOSTIC_HPP
#define MATIEC_DIAGNOSTICS_DIAGNOSTIC_HPP

#include "../error.hpp"
#include <fmt/format.h>  // 或 std::format (C++20)

namespace matiec::diagnostics {

/**
 * @brief 诊断消息构建器
 *
 * 使用流畅接口构建详细的诊断消息。
 */
class DiagnosticBuilder {
public:
    DiagnosticBuilder(ErrorReporter& reporter, ErrorSeverity severity)
        : reporter_(reporter), severity_(severity) {}

    DiagnosticBuilder& at(const ast::Symbol& symbol) {
        if (auto range = symbol.range(); range.isValid()) {
            location_ = SourceLocation{
                std::string(range.start.filename),
                range.start.line,
                range.start.column
            };
        }
        return *this;
    }

    DiagnosticBuilder& at(SourceLocation loc) {
        location_ = std::move(loc);
        return *this;
    }

    DiagnosticBuilder& category(ErrorCategory cat) {
        category_ = cat;
        return *this;
    }

    template<typename... Args>
    void message(std::string_view fmt, Args&&... args) {
        auto msg = fmt::format(fmt::runtime(fmt), std::forward<Args>(args)...);
        reporter_.report(severity_, category_, std::move(msg), location_);
    }

private:
    ErrorReporter& reporter_;
    ErrorSeverity severity_;
    ErrorCategory category_ = ErrorCategory::Semantic;
    std::optional<SourceLocation> location_;
};

/**
 * @brief 诊断发射器
 */
class Diagnostics {
public:
    explicit Diagnostics(ErrorReporter& reporter) : reporter_(reporter) {}

    [[nodiscard]] DiagnosticBuilder error() {
        return DiagnosticBuilder(reporter_, ErrorSeverity::Error);
    }

    [[nodiscard]] DiagnosticBuilder warning() {
        return DiagnosticBuilder(reporter_, ErrorSeverity::Warning);
    }

    [[nodiscard]] DiagnosticBuilder note() {
        return DiagnosticBuilder(reporter_, ErrorSeverity::Note);
    }

    // 预定义诊断消息
    void undeclaredVariable(const ast::Symbol& symbol, std::string_view name) {
        error()
            .at(symbol)
            .category(ErrorCategory::Semantic)
            .message("undeclared variable '{}'", name);
    }

    void typeMismatch(const ast::Symbol& symbol,
                      std::string_view expected,
                      std::string_view actual) {
        error()
            .at(symbol)
            .category(ErrorCategory::Type)
            .message("type mismatch: expected '{}', got '{}'", expected, actual);
    }

    void divisionByZero(const ast::Symbol& symbol) {
        warning()
            .at(symbol)
            .category(ErrorCategory::Semantic)
            .message("division by zero");
    }

private:
    ErrorReporter& reporter_;
};

} // namespace matiec::diagnostics

#endif // MATIEC_DIAGNOSTICS_DIAGNOSTIC_HPP
```

---

## 8. 代码生成器重构

### 8.1 当前架构问题

```cpp
// 当前: 大量字符串拼接
s4o.print("void ");
s4o.print(FB_FUNCTION_SUFFIX);
s4o.print("(");
// ...
```

### 8.2 现代代码生成器

```cpp
// include/matiec/codegen/code_emitter.hpp

#ifndef MATIEC_CODEGEN_CODE_EMITTER_HPP
#define MATIEC_CODEGEN_CODE_EMITTER_HPP

#include <string>
#include <string_view>
#include <ostream>
#include <sstream>
#include <memory>

namespace matiec::codegen {

/**
 * @brief 代码发射器 - 结构化的代码输出
 */
class CodeEmitter {
public:
    explicit CodeEmitter(std::ostream& output) : output_(output) {}

    // ========== 缩进管理 ==========

    void indent() { indentLevel_++; }
    void dedent() { if (indentLevel_ > 0) indentLevel_--; }

    class IndentGuard {
    public:
        explicit IndentGuard(CodeEmitter& e) : emitter_(e) { emitter_.indent(); }
        ~IndentGuard() { emitter_.dedent(); }
        IndentGuard(const IndentGuard&) = delete;
        IndentGuard& operator=(const IndentGuard&) = delete;
    private:
        CodeEmitter& emitter_;
    };

    [[nodiscard]] IndentGuard indented() { return IndentGuard(*this); }

    // ========== 输出方法 ==========

    CodeEmitter& write(std::string_view text) {
        output_ << text;
        return *this;
    }

    CodeEmitter& writeLine(std::string_view text = "") {
        writeIndent();
        output_ << text << '\n';
        return *this;
    }

    template<typename... Args>
    CodeEmitter& writef(std::string_view fmt, Args&&... args) {
        // 使用 fmt 库或 std::format
        output_ << fmt::format(fmt::runtime(fmt), std::forward<Args>(args)...);
        return *this;
    }

    template<typename... Args>
    CodeEmitter& writeLinef(std::string_view fmt, Args&&... args) {
        writeIndent();
        writef(fmt, std::forward<Args>(args)...);
        output_ << '\n';
        return *this;
    }

    // ========== 块结构 ==========

    /**
     * @brief 写入代码块
     * @param header 块头 (如 "if (condition)")
     * @param body 块内容生成函数
     */
    template<typename Func>
    void block(std::string_view header, Func&& body) {
        writeLinef("{} {{", header);
        {
            auto guard = indented();
            std::forward<Func>(body)();
        }
        writeLine("}");
    }

    /**
     * @brief 写入函数定义
     */
    template<typename Func>
    void function(std::string_view returnType,
                  std::string_view name,
                  std::string_view params,
                  Func&& body) {
        writeLinef("{} {}({}) {{", returnType, name, params);
        {
            auto guard = indented();
            std::forward<Func>(body)();
        }
        writeLine("}");
        writeLine();
    }

    // ========== 注释 ==========

    void lineComment(std::string_view text) {
        writeLinef("// {}", text);
    }

    void blockComment(std::string_view text) {
        writeLine("/*");
        writeLine(text);
        writeLine("*/");
    }

private:
    void writeIndent() {
        for (int i = 0; i < indentLevel_; ++i) {
            output_ << "    ";  // 4 空格缩进
        }
    }

    std::ostream& output_;
    int indentLevel_ = 0;
};

/**
 * @brief C 代码生成器
 */
class CCodeGenerator : public ast::IteratorVisitor {
public:
    explicit CCodeGenerator(std::ostream& output)
        : emitter_(output) {}

    void generate(const ast::Symbol& tree);

    // 访问者方法
    ast::VisitorResult visit(ast::ProgramDeclaration& symbol) override;
    ast::VisitorResult visit(ast::FunctionDeclaration& symbol) override;
    ast::VisitorResult visit(ast::FunctionBlockDeclaration& symbol) override;
    ast::VisitorResult visit(ast::AssignmentStatement& symbol) override;
    // ... 其他节点

private:
    CodeEmitter emitter_;
};

} // namespace matiec::codegen

#endif // MATIEC_CODEGEN_CODE_EMITTER_HPP
```

### 8.3 代码生成示例

```cpp
// 示例: 生成函数块代码
ast::VisitorResult CCodeGenerator::visit(ast::FunctionBlockDeclaration& symbol) {
    auto* name = symbol.name();

    // 生成类型定义
    emitter_.writeLinef("typedef struct {{");
    {
        auto guard = emitter_.indented();
        // 生成变量声明...
        if (auto* vars = symbol.varDeclarations()) {
            vars->accept(*this);
        }
    }
    emitter_.writeLinef("}} {};\n", name->value());

    // 生成初始化函数
    emitter_.function("void",
        fmt::format("{}_init", name->value()),
        fmt::format("{}* self", name->value()),
        [&] {
            emitter_.lineComment("Initialize all variables");
            // ...
        });

    // 生成执行函数
    emitter_.function("void",
        fmt::format("{}_body", name->value()),
        fmt::format("{}* self", name->value()),
        [&] {
            if (auto* body = symbol.body()) {
                body->accept(*this);
            }
        });

    return {};
}
```

---

## 9. 符号表与作用域管理

### 9.1 现代化符号表

```cpp
// include/matiec/semantic/symbol_table.hpp

#ifndef MATIEC_SEMANTIC_SYMBOL_TABLE_HPP
#define MATIEC_SEMANTIC_SYMBOL_TABLE_HPP

#include "../ast/symbol.hpp"
#include "../types/type.hpp"
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include <memory>
#include <optional>

namespace matiec::semantic {

/**
 * @brief 符号条目
 */
struct SymbolEntry {
    enum class Kind {
        Variable,
        Constant,
        Type,
        Function,
        FunctionBlock,
        Program
    };

    std::string name;
    Kind kind;
    std::shared_ptr<const types::Type> type;
    ast::Symbol* declaration = nullptr;  // 指向 AST 中的声明

    // 变量特有属性
    bool isInput = false;
    bool isOutput = false;
    bool isInOut = false;
    bool isLocal = false;
    bool isExternal = false;
    bool isGlobal = false;
    bool isRetain = false;
    bool isConstant = false;
};

/**
 * @brief 作用域
 */
class Scope {
public:
    explicit Scope(Scope* parent = nullptr) : parent_(parent) {}

    /**
     * @brief 在当前作用域定义符号
     * @return 是否成功 (失败表示重复定义)
     */
    [[nodiscard]] bool define(SymbolEntry entry);

    /**
     * @brief 在当前作用域查找符号
     */
    [[nodiscard]] SymbolEntry* lookupLocal(std::string_view name);
    [[nodiscard]] const SymbolEntry* lookupLocal(std::string_view name) const;

    /**
     * @brief 在当前及所有父作用域查找符号
     */
    [[nodiscard]] SymbolEntry* lookup(std::string_view name);
    [[nodiscard]] const SymbolEntry* lookup(std::string_view name) const;

    /**
     * @brief 获取父作用域
     */
    [[nodiscard]] Scope* parent() const noexcept { return parent_; }

    /**
     * @brief 获取所有本地符号
     */
    [[nodiscard]] const auto& symbols() const noexcept { return symbols_; }

private:
    // 大小写不敏感的字符串比较
    struct CaseInsensitiveHash {
        size_t operator()(std::string_view s) const noexcept;
    };
    struct CaseInsensitiveEqual {
        bool operator()(std::string_view a, std::string_view b) const noexcept;
    };

    using SymbolMap = std::unordered_map<
        std::string,
        SymbolEntry,
        CaseInsensitiveHash,
        CaseInsensitiveEqual
    >;

    SymbolMap symbols_;
    Scope* parent_;
};

/**
 * @brief 符号表 - 管理作用域栈
 */
class SymbolTable {
public:
    SymbolTable();

    /**
     * @brief 进入新作用域
     */
    void enterScope();

    /**
     * @brief 退出当前作用域
     */
    void exitScope();

    /**
     * @brief 获取当前作用域
     */
    [[nodiscard]] Scope& currentScope() noexcept { return *scopes_.back(); }
    [[nodiscard]] const Scope& currentScope() const noexcept { return *scopes_.back(); }

    /**
     * @brief 在当前作用域定义符号
     */
    [[nodiscard]] bool define(SymbolEntry entry) {
        return currentScope().define(std::move(entry));
    }

    /**
     * @brief 查找符号
     */
    [[nodiscard]] SymbolEntry* lookup(std::string_view name) {
        return currentScope().lookup(name);
    }

    /**
     * @brief 作用域深度
     */
    [[nodiscard]] size_t depth() const noexcept { return scopes_.size(); }

    /**
     * @brief RAII 作用域守卫
     */
    class ScopeGuard {
    public:
        explicit ScopeGuard(SymbolTable& table) : table_(table) { table_.enterScope(); }
        ~ScopeGuard() { table_.exitScope(); }
        ScopeGuard(const ScopeGuard&) = delete;
        ScopeGuard& operator=(const ScopeGuard&) = delete;
    private:
        SymbolTable& table_;
    };

    [[nodiscard]] ScopeGuard scopeGuard() { return ScopeGuard(*this); }

private:
    std::vector<std::unique_ptr<Scope>> scopes_;
};

} // namespace matiec::semantic

#endif // MATIEC_SEMANTIC_SYMBOL_TABLE_HPP
```

---

## 10. API 现代化

### 10.1 C++ 公共 API

```cpp
// include/matiec/matiec.hpp

#ifndef MATIEC_HPP
#define MATIEC_HPP

#include "error.hpp"
#include "ast/symbol.hpp"
#include "compiler/compilation_unit.hpp"
#include "types/type.hpp"

#include <string>
#include <string_view>
#include <memory>
#include <optional>
#include <filesystem>

namespace matiec {

/**
 * @brief 编译选项
 */
struct CompilerOptions {
    std::filesystem::path outputDir = ".";
    std::filesystem::path includeDir;

    enum class OutputFormat { C, IEC };
    OutputFormat outputFormat = OutputFormat::C;

    bool allowForwardRefs = false;
    bool relaxedDatatypeModel = false;
    bool safeExtensions = false;
    bool nestingComments = false;
    bool refToDerived = false;
    bool enableDeadCodeWarnings = true;

    int maxErrors = 0;  // 0 = unlimited
};

/**
 * @brief 编译结果
 */
struct CompilerResult {
    bool success = false;
    std::vector<std::string> outputFiles;
    std::unique_ptr<compiler::CompilationUnit> compilationUnit;

    [[nodiscard]] const ErrorReporter& errors() const noexcept {
        return compilationUnit ? compilationUnit->errors() : emptyReporter_;
    }

private:
    static ErrorReporter emptyReporter_;
};

/**
 * @brief 编译器类
 *
 * 主要入口点，提供完整的编译功能。
 */
class Compiler {
public:
    Compiler();
    explicit Compiler(CompilerOptions options);
    ~Compiler();

    // 不可复制
    Compiler(const Compiler&) = delete;
    Compiler& operator=(const Compiler&) = delete;

    // 可移动
    Compiler(Compiler&&) noexcept;
    Compiler& operator=(Compiler&&) noexcept;

    /**
     * @brief 编译文件
     */
    [[nodiscard]] CompilerResult compileFile(const std::filesystem::path& inputFile);

    /**
     * @brief 编译字符串
     */
    [[nodiscard]] CompilerResult compileString(
        std::string_view source,
        std::string_view sourceName = "<string>"
    );

    /**
     * @brief 仅解析 (不进行语义分析和代码生成)
     */
    [[nodiscard]] CompilerResult parseFile(const std::filesystem::path& inputFile);
    [[nodiscard]] CompilerResult parseString(
        std::string_view source,
        std::string_view sourceName = "<string>"
    );

    /**
     * @brief 获取/修改选项
     */
    [[nodiscard]] const CompilerOptions& options() const noexcept;
    void setOptions(CompilerOptions options);

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};

/**
 * @brief 便捷函数: 编译文件
 */
[[nodiscard]] inline CompilerResult compile(
    const std::filesystem::path& inputFile,
    const CompilerOptions& options = {}
) {
    return Compiler(options).compileFile(inputFile);
}

/**
 * @brief 便捷函数: 编译字符串
 */
[[nodiscard]] inline CompilerResult compile(
    std::string_view source,
    std::string_view sourceName = "<string>",
    const CompilerOptions& options = {}
) {
    return Compiler(options).compileString(source, sourceName);
}

} // namespace matiec

#endif // MATIEC_HPP
```

### 10.2 保留 C API 兼容性

现有的 `include/matiec/matiec.h` C API 保持不变，内部实现使用新的 C++ API。

---

## 11. 迁移策略

### 11.1 分阶段计划

```
┌─────────────────────────────────────────────────────────────────────┐
│                     迁移时间线                                      │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│  Phase 1: 基础设施 (已部分完成)                                    │
│  ├─ [x] error.hpp - 现代错误处理                                   │
│  ├─ [x] string_utils.hpp - 字符串工具                              │
│  ├─ [x] symtable.hh - 符号表现代化                                 │
│  ├─ [ ] visitor_result.hpp - 访问者返回类型                        │
│  └─ [ ] compilation_unit.hpp - 编译单元封装                        │
│                                                                     │
│  Phase 2: AST 现代化                                                │
│  ├─ [ ] 更新 gen_absyntax.py 生成新式节点                          │
│  ├─ [ ] 添加适配层支持旧代码                                       │
│  ├─ [ ] 迁移 absyntax.hh 基类                                      │
│  └─ [ ] 更新 visitor.hh 接口                                       │
│                                                                     │
│  Phase 3: 类型系统                                                  │
│  ├─ [ ] 实现 Type 类层次结构                                       │
│  ├─ [ ] 实现 TypeRegistry                                          │
│  ├─ [ ] 实现 TypeInferrer                                          │
│  └─ [ ] 迁移 get_datatype_info_c                                   │
│                                                                     │
│  Phase 4: 语义分析                                                  │
│  ├─ [ ] 迁移 fill_candidate_datatypes_c                            │
│  ├─ [ ] 迁移 narrow_candidate_datatypes_c                          │
│  ├─ [ ] 迁移 constant_folding_c                                    │
│  └─ [ ] 迁移其他 stage3 组件                                       │
│                                                                     │
│  Phase 5: 代码生成                                                  │
│  ├─ [ ] 实现 CodeEmitter                                           │
│  ├─ [ ] 迁移 generate_c                                            │
│  ├─ [ ] 迁移 generate_iec                                          │
│  └─ [ ] 添加代码生成器单元测试                                     │
│                                                                     │
│  Phase 6: 集成与清理                                                │
│  ├─ [ ] 移除兼容层                                                 │
│  ├─ [ ] 移除旧式 void* 接口                                        │
│  ├─ [ ] 更新文档                                                   │
│  └─ [ ] 性能基准测试                                               │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

### 11.2 迁移原则

1. **渐进式**: 每个 PR 应该是独立可工作的
2. **测试驱动**: 先写测试，再迁移代码
3. **兼容性**: 始终保持 C API 和命令行接口兼容
4. **可回滚**: 每个阶段可独立回滚

### 11.3 风险管理

| 风险 | 缓解措施 |
|------|---------|
| 生成代码大量修改 | 保留旧生成器，新旧并行 |
| 性能退化 | 基准测试，Profile-guided 优化 |
| 行为变化 | 端到端测试覆盖所有语言特性 |
| Flex/Bison 兼容性 | 接口适配层隔离 |

---

## 12. 附录

### A. 目录结构 (目标状态)

```
matiec-cmake/
├── include/matiec/
│   ├── matiec.h              # C API (保持不变)
│   ├── matiec.hpp            # Modern C++ API (新增)
│   ├── error.hpp             # (已现代化)
│   ├── string_utils.hpp      # (已现代化)
│   ├── ast/
│   │   ├── symbol.hpp        # AST 基类
│   │   ├── visitor.hpp       # 访问者接口
│   │   ├── visitor_result.hpp
│   │   ├── declarations.hpp
│   │   ├── expressions.hpp
│   │   ├── statements.hpp
│   │   └── generated/        # 生成的节点类
│   ├── types/
│   │   ├── type.hpp
│   │   ├── type_registry.hpp
│   │   └── type_inferrer.hpp
│   ├── semantic/
│   │   ├── symbol_table.hpp
│   │   └── scope.hpp
│   ├── codegen/
│   │   ├── code_emitter.hpp
│   │   └── c_generator.hpp
│   ├── compiler/
│   │   └── compilation_unit.hpp
│   └── diagnostics/
│       └── diagnostic.hpp
├── src/
│   ├── matiec_lib.cc         # 库实现
│   ├── ast/
│   ├── types/
│   ├── semantic/
│   ├── codegen/
│   └── compiler/
├── stage1_2/                 # Flex/Bison (保留结构)
├── stage3/                   # 逐步迁移到 src/semantic
├── stage4/                   # 逐步迁移到 src/codegen
└── tests/
    ├── unit/
    │   ├── ast/
    │   ├── types/
    │   ├── semantic/
    │   └── codegen/
    └── e2e/
```

### B. 编码规范

#### B.1 命名约定

| 类型 | 约定 | 示例 |
|------|------|------|
| 类/结构体 | PascalCase | `SymbolTable`, `TypeRegistry` |
| 函数/方法 | camelCase | `enterScope()`, `lookupLocal()` |
| 变量 | camelCase | `currentScope`, `indentLevel` |
| 常量 | UPPER_SNAKE | `MAX_ERRORS`, `DEFAULT_INDENT` |
| 命名空间 | lowercase | `matiec::ast`, `matiec::types` |
| 私有成员 | trailing_ | `parent_`, `elements_` |

#### B.2 文件组织

- 每个类一个头文件
- 实现文件与头文件同名 (`.cc`)
- 使用 `#pragma once` 或传统 include guard
- 包含顺序: 本模块头 > 项目头 > 第三方 > 标准库

#### B.3 Modern C++ 特性使用

```cpp
// 推荐使用
std::unique_ptr<T>           // 代替 T*
std::string_view             // 代替 const char*
std::optional<T>             // 代替 T* (可选值)
[[nodiscard]]                // 返回值不应忽略
[[noexcept]]                 // 性能关键路径
constexpr                    // 编译期计算
auto                         // 类型推导 (适度使用)

// 避免使用
void*                        // 使用 std::variant 或模板
new/delete                   // 使用智能指针
strcpy/sprintf               // 使用 std::string
#define                      // 使用 constexpr/inline
```

### C. 参考资料

1. C++ Core Guidelines: https://isocpp.github.io/CppCoreGuidelines/
2. Effective Modern C++ (Scott Meyers)
3. IEC 61131-3 Standard, 2nd/3rd Edition
4. LLVM Coding Standards (visitor pattern reference)

---

*文档版本: 1.0*
*最后更新: 2026-01-24*
