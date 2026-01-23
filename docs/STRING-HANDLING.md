# 编译器字符串处理：模型、边界与迁移建议（P3）

本文面向 matiec 的“编译器实现代码”（lexer/parser/AST/stage3/stage4/C API），目标是明确字符串的生命周期与边界，避免：
- `std::string_view` 绑定到失效内存（UAF）
- 把 NULL 直接传入 `std::string_view`（UB）
- 大小写无关比较实现不一致（跨平台差异/逻辑 bug）
- 依赖固定长度缓冲区的路径/临时文件实现（平台差异/截断）

非目标：
- 不修改 IEC 运行时库（`lib/C/*`）里 `STR_MAX_LEN` 等字符串类型语义。

## 1. 现状：三类字符串来源

### 1.1 Token/标识符等：来自 lexer/parser
阶段 `stage1_2`（Flex/Bison）会产生大量 token 文本（标识符、字面量、文件名等）。

当前策略：
- lexer 会把部分 token 文本放入 `matiec::cstr_pool_*`（见 `absyntax/ast_memory.cc`），并在一次编译结束时统一 `cstr_pool_clear()`。
- Bison 的 `%union` 仍以 `char*` 承载 token 值（例如 `yylval.ID`），便于与历史代码兼容。

约束：
- 这些 `char*` **只保证在“本次编译（per-compilation）”内有效**；下一次编译开始清理后不可再持有。

### 1.2 AST token 节点：`token_c::value`
`token_c` 内部使用 `matiec::token_string` 存储 token 文本，同时保留历史调用点对 `const char*` 的访问方式（`token->value`）。

约束：
- `token_string::c_str()` 在 `is_null()` 为真时返回 `nullptr`（保留历史“NULL 表示无字符串”的约定）。
- 不要把 `token->value.c_str()` 的指针跨 AST 生命周期保存。

### 1.3 对外接口字符串：C API / CLI 参数
`matiec_compile_file/string` 等对外接口以 `const char*` 接收参数；内部应尽量快速转换为 `std::string_view`/`std::filesystem::path`，避免手写拼接与固定缓冲区。

## 2. 核心边界：`std::string_view` 的使用规则

必须遵守：
1) `std::string_view` **只绑定到稳定存活的内存**：
   - `std::string`（且在 view 存活期间不发生修改/重分配）
   - 字符串字面量
   - 本次编译周期内的 `cstr_pool` 字符串
2) 严禁：把可能为 NULL 的 `const char*` 直接隐式转换为 `std::string_view`。

推荐用法：
- 统一使用 `matiec::sv_or_empty(const char*)`（见 `include/matiec/string_utils.hpp`）把 NULL 转为空 view，再进入 `string_view` 世界。

## 3. 大小写无关比较：统一入口

历史代码里常见两类需求：
- “用于排序/作为 map comparator”的 **less-than**（严格弱序）
- “判断相等”的 **equals**

注意：**less-than comparator 不是 equals**。
如果把 comparator 当 equals，会产生“相等时返回 false”的逻辑 bug。

统一建议：
- 比较相等：`matiec::iequals(a, b)` / `matiec::iequals(const char*, const char*)`
- 判断前缀：`matiec::istarts_with(...)`
- 排序：使用提供严格弱序的 comparator（例如 `nocasecmp_c`），并在需要 equals 的地方显式用 `iequals`。

## 4. 路径与临时文件

优先使用：
- `std::filesystem::path` 做路径拼接/规范化（避免手写 `dir + "/" + file`）
- 临时文件：优先“随机名 + 独占创建”的方式，避免依赖 `MAX_PATH` 固定缓冲区或不安全的 `tmpnam`

## 5. 渐进式迁移建议（P3）

建议顺序：
1) 先补齐基础工具与约定（NULL-safe 的 `string_view` 转换、统一大小写比较函数）
2) 修复明显的 comparator 误用（把 less-than 当 equals 的位置）
3) 再做路径/临时文件封装，减少平台差异
4) 最后再评估是否要把 Bison `%union` 从 `char*` 升级为 `std::string/std::string_view`（风险高，需单独 issue）

