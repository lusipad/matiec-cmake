# Change: 仓库目录结构现代化整合

## Why

当前仓库存在以下问题：
1. **过期文件冗余** — `CMAKE_MIGRATION_PLAN.md` 已完成但仍留在根目录；`AGENTS.md` 重复定义了 `CLAUDE.md` 中的内容
2. **临时/调试文件遗留** — 根目录残留 `POUS.c/h`, `LOCATED_VARIABLES.h`, `VARIABLES.csv` 等编译输出（尽管已在 `.gitignore`）
3. **IDE 特定配置** — `.settings/` 是 Eclipse CDT 配置，与 CMake 项目无关
4. **遗留包管理** — `debian/` 和 `matiec.nuspec` 属于传统打包方式，不再维护
5. **issues 目录膨胀** — 大量已完成的 issue CSV 文件占据空间，缺乏归档机制
6. **文档分散** — 关键文档散落在多处（`docs/`, `openspec/`, 根目录）
7. **根目录层级过深** — 顶层目录过多且粒度不一致，难以快速定位主代码与文档入口

需要按照现代化仓库实践进行整合，提升可维护性和开发者体验。

## What Changes

### 顶层目录收敛 (CONSOLIDATE ROOT)
- 定义根目录一级目录白名单，仅保留：`src/`, `docs/`, `cmake/`, `config/`, `tests/`, `tools/`, `openspec/`
- 将现有顶层目录归并到白名单目录下（示例：`absyntax/`, `stage1_2/`, `stage3/`, `stage4/`, `lib/`, `util/`, `include/` → `src/`）
- 根目录仅保留必要入口文件（`CMakeLists.txt`, `README.md`, `COPYING` 等），其余移动或归档

### 移除 (REMOVE)
- `/CMAKE_MIGRATION_PLAN.md` — 迁移已完成，作为历史文档移至 `docs/architecture/`
- `/.settings/` — Eclipse CDT 配置，与项目无关
- `/debian/` — 遗留 Debian 包配置，建议用 CPack 替代
- `/matiec.nuspec` — 遗留 NuGet 包配置，URL 占位符未更新
- `/POUS.c`, `/POUS.h`, `/LOCATED_VARIABLES.h`, `/VARIABLES.csv` — 根目录下的编译输出残留

### 归档 (ARCHIVE)
- `/issues/*.csv` 和 `/issues/*.md` — 已完成的 issue 移至 `/tools/issues/archive/`
- 仅保留 `/tools/issues/README.md` 与 `/tools/issues/TODO.md`

### 整合 (CONSOLIDATE)
- `/docs/` 保持现状并新增：
  - `docs/architecture/` — 架构文档 (含 `legacy/ARCHITECTURE.txt`)
  - `docs/reference/AnnexF/` — IEC 标准附录

### 更新 (UPDATE)
- `.gitignore` — 确保根目录编译输出被忽略且无需手动清理
- `CLAUDE.md` — 保留；如需更新仅指向 `openspec/AGENTS.md`

## Impact

- **Affected files**: 预计显著增加（目录归并涉及更多文件/路径）
- **Breaking changes**: 可能存在（移动目录需要同步更新构建/包含路径）
- **Risk level**: 中
- **Rollback**: Git 历史可完全恢复

## Out of Scope

- 业务逻辑/功能变更（仅目录与路径调整）
- CI/CD 配置调整
- 构建系统策略变更（仅更新路径引用）

## Open Questions

暂无
