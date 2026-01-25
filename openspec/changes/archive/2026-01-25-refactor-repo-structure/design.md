# Design: 仓库目录结构现代化整合

## Context

matiec-cmake 项目从 Autotools 迁移到 CMake 构建系统后，仓库中遗留了大量过期文件和配置。随着项目的持续开发，`issues/` 目录积累了大量已完成的任务追踪文件。需要进行一次全面的仓库整理，以符合现代开源项目的最佳实践。

**当前状态**:
```
matiec-cmake/
├── .claude/              # Claude Code 配置
├── .github/              # GitHub 工作流
├── .settings/            # ❌ Eclipse CDT (过期)
├── absyntax/             # ✅ AST 核心
├── absyntax_utils/       # ✅ AST 工具
├── AnnexF/               # ✅ IEC 标准附录
├── build*/               # 构建目录 (gitignore)
├── cmake/                # ✅ CMake 模块
├── config/               # ✅ 配置模板
├── debian/               # ❌ 过期打包
├── docs/                 # ✅ 文档 (需整理)
├── include/              # ✅ 公共头文件
├── issues/               # ⚠️ 需归档
├── lib/                  # ✅ 运行时库
├── openspec/             # ✅ OpenSpec
├── src/                  # ✅ 源码
├── stage1_2/             # ✅ 词法/语法分析
├── stage3/               # ✅ 语义分析
├── stage4/               # ✅ 代码生成
├── tests/                # ✅ 测试
├── util/                 # ✅ 工具类
├── vcpkg-port/           # ✅ vcpkg 集成
├── AGENTS.md             # ✅ Codex 配置 (保留)
├── CMAKE_MIGRATION_PLAN.md # ❌ 过期 (归档)
├── matiec.nuspec         # ❌ 过期 (删除)
├── POUS.*, LOCATED_*, VARIABLES.* # ❌ 编译残留 (删除)
└── ...
```

## Goals / Non-Goals

### Goals
- 移除所有过期/冗余文件和目录
- 归档已完成的 issue 追踪文件
- 建立清晰的文档组织结构
- 收敛根目录一级目录到白名单
- 保持构建可用（通过更新路径引用）

### Non-Goals
- 业务逻辑/模块职责调整（仅目录归并）
- 引入新的构建系统或策略（仅更新路径引用）
- 添加新的 CI/CD 工作流
- 迁移到新的打包系统（CPack 等）

## Decisions

### D1: 过期配置处理策略

| 文件/目录 | 决策 | 理由 |
|-----------|------|------|
| `.settings/` | 删除 | Eclipse CDT 配置，与 CMake 项目无关 |
| `debian/` | 删除 | 未维护，URL/版本过期 |
| `matiec.nuspec` | 删除 | 占位符 URL 未更新，未实际使用 |
| `CMAKE_MIGRATION_PLAN.md` | 归档 | 有历史参考价值，移至 `docs/architecture/` |
| `AGENTS.md` | 保留 | Codex 使用的配置文件 |

**替代方案**: 保留 `debian/` 和 `matiec.nuspec` 并更新。
**否决原因**: 维护成本高，优先级低，未来可按需重新添加。

### D2: Issues 归档策略

归档并迁移至 `tools/issues/`：
```
tools/
└── issues/
    ├── README.md           # 保留
    ├── TODO.md             # 保留 (活跃)
    └── archive/
        ├── p0-*.csv
        ├── p1-*.csv
        └── ...
```

**替代方案**: 按月归档或保留在根目录。
**选择理由**: 满足根目录收敛要求，结构清晰且便于检索。

### D3: 文档目录结构

```
docs/
├── AST-OWNERSHIP.md     # AST 所有权
├── INTEGRATION.md       # 集成指南
├── MODERNC_DESIGN.md    # 设计文档
├── README.md            # 文档索引
├── STRING-HANDLING.md   # 字符串指南
├── STYLE.md             # 代码风格
├── mcp-tools.md         # 工具说明
├── perf-checklist.md    # 性能检查清单
├── testing-policy.md    # 测试策略
├── architecture/
│   └── ARCHITECTURE.txt # 原 legacy/ 内容
└── reference/
    └── AnnexF/          # IEC 标准附录
```

**简化替代**: 保持现有扁平结构。
**选择理由**: 当前文档量有限，可推迟重组到文档增多时。

**最终决策**: 归档 `legacy/ARCHITECTURE.txt` 并新增 `docs/reference/AnnexF/`，其余保持现状。

### D4: 根目录白名单与迁移映射

根目录一级目录白名单：`src/`, `docs/`, `cmake/`, `config/`, `tests/`, `tools/`, `openspec/`（不含隐藏目录）。

| 现有目录/文件 | 目标位置 | 说明 |
|---------------|----------|------|
| `absyntax/` | `src/absyntax/` | AST 核心 |
| `absyntax_utils/` | `src/absyntax_utils/` | AST 工具 |
| `include/` | `src/include/` | 公共头文件 |
| `lib/` | `src/lib/` | 运行时库 |
| `stage1_2/` | `src/stage1_2/` | 词法/语法分析 |
| `stage3/` | `src/stage3/` | 语义分析 |
| `stage4/` | `src/stage4/` | 代码生成 |
| `util/` | `src/util/` | 工具类 |
| `main.cc`, `main.hh` | `src/` | 入口源码 |
| `AnnexF/` | `docs/reference/AnnexF/` | IEC 标准附录 |
| `issues/` | `tools/issues/` | Issue CSV 管理 |
| `openspec/` | `openspec/` | OpenSpec 规范与变更（保持根目录） |
| `vcpkg-port/` | `tools/vcpkg-port/` | vcpkg 集成 |

**说明**: `.github/`, `.claude/`, `.git/` 等隐藏目录保持在根目录；本地构建目录继续由 `.gitignore` 管理。

## Risks / Trade-offs

| 风险 | 影响 | 缓解措施 |
|------|------|----------|
| 删除文件后有人依赖 | 低 | Git 历史可恢复；先发布公告 |
| 破坏外部链接 | 低 | 项目为内部使用，无公开 URL |
| 归档后难以查找 | 中 | 在 `issues/README.md` 添加归档说明 |
| 路径迁移导致构建失败 | 中 | 更新 CMake 与脚本路径，执行构建与测试 |
| 工具引用路径过期 | 中 | 全局搜索并更新引用（文档、脚本、说明） |

## Migration Plan

1. **Phase 1** (立即执行): 删除明确过期的文件
2. **Phase 2** (同批次): 归档并迁移 issues 至 `tools/`
3. **Phase 3** (同批次): 迁移文档目录（`architecture/`, `reference/AnnexF`）
4. **Phase 4** (同批次): 收敛顶层目录并更新路径引用
5. **Rollback**: `git revert` 相关提交

## Target Structure

```
matiec-cmake/
├── .claude/              # Claude Code 配置
├── .github/              # GitHub 工作流
├── cmake/                # CMake 模块
├── config/               # 配置模板
├── docs/
│   ├── architecture/     # 架构文档
│   │   └── ARCHITECTURE.txt
│   ├── reference/        # 参考文档
│   │   └── AnnexF/        # IEC 标准附录
│   └── ...               # 其他文档保持现状
├── openspec/             # OpenSpec
├── src/                  # 源码
│   ├── absyntax/
│   ├── absyntax_utils/
│   ├── include/
│   ├── lib/
│   ├── stage1_2/
│   ├── stage3/
│   ├── stage4/
│   └── util/
├── tests/                # 测试
├── tools/                # 工具
│   ├── issues/
│   │   ├── README.md
│   │   ├── TODO.md
│   │   └── archive/      # 归档的 issues
│   └── vcpkg-port/
├── AGENTS.md             # Codex 配置
├── CLAUDE.md             # Claude Code 配置
├── CMakeLists.txt        # 根构建文件
├── COPYING               # 许可证
└── README.md             # 项目说明
```

## Open Questions

暂无
