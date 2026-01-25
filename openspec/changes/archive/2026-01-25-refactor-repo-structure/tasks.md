# Tasks: 仓库目录结构现代化整合

## 1. 清理根目录遗留文件
- [x] 1.1 移动 `CMAKE_MIGRATION_PLAN.md` 到 `docs/architecture/CMAKE_MIGRATION_PLAN.md`
- [x] 1.2 删除根目录编译输出残留：`POUS.c`, `POUS.h`, `LOCATED_VARIABLES.h`, `VARIABLES.csv`

## 2. 移除过期的配置目录
- [x] 2.1 删除 `/.settings/` 目录（Eclipse CDT 配置）
- [x] 2.2 删除 `/debian/` 目录（遗留 Debian 打包配置）
- [x] 2.3 删除 `/matiec.nuspec`（遗留 NuGet 配置）

## 3. 归档并迁移 issues
- [x] 3.1 创建 `/tools/issues/archive/` 目录
- [x] 3.2 移动所有已完成的 `issues/p*.csv` 和 `issues/p*.md` 到 `/tools/issues/archive/`
- [x] 3.3 移动 `issues/README.md` 和 `issues/TODO.md` 到 `/tools/issues/`
- [x] 3.4 删除空的 `/issues/` 目录

## 4. 重组文档目录
- [x] 4.1 创建 `docs/architecture/` 目录
- [x] 4.2 移动 `docs/legacy/ARCHITECTURE.txt` 到 `docs/architecture/`
- [x] 4.3 删除空的 `docs/legacy/` 目录
- [x] 4.4 创建 `docs/reference/` 并移动 `AnnexF/` 到 `docs/reference/AnnexF/`
- [x] 4.5 评估并整合 `docs/` 下的文档结构（如有必要）

## 5. 顶层目录收敛
- [x] 5.1 迁移代码目录到 `src/`：
  `absyntax/` → `src/absyntax/`，
  `absyntax_utils/` → `src/absyntax_utils/`，
  `include/` → `src/include/`，
  `lib/` → `src/lib/`，
  `stage1_2/` → `src/stage1_2/`，
  `stage3/` → `src/stage3/`，
  `stage4/` → `src/stage4/`，
  `util/` → `src/util/`
- [x] 5.2 移动 `main.cc` 和 `main.hh` 到 `src/`
- [x] 5.3 创建 `tools/` 并迁移工具目录：`vcpkg-port/` → `tools/vcpkg-port/`（`openspec/` 保持根目录）
- [x] 5.4 更新路径引用（`CMakeLists.txt`、`cmake/` 脚本、文档链接、测试数据）

## 6. 更新配置文件
- [x] 6.1 保留 `CLAUDE.md`（不删除）；如需更新，仅同步指向 `openspec/AGENTS.md`
- [x] 6.2 验证 `.gitignore` 是否正确忽略根目录编译输出

## 7. 验证与测试
- [x] 7.1 运行 `cmake --build` 确保构建正常
- [x] 7.2 运行 `ctest` 确保测试通过
- [x] 7.3 检查 `git status` 确保所有变更正确跟踪

## Dependencies
- 任务 1-2 可并行执行
- 任务 3-5 依赖任务 1-2 完成
- 任务 6 依赖任务 3-5 完成
- 任务 7 依赖所有前置任务完成

## Acceptance Criteria
- 根目录无过期/冗余文件
- 已完成 issues 正确归档并迁移至 `tools/issues/`
- 文档结构清晰易导航
- 根目录仅保留 `src/`, `docs/`, `cmake/`, `config/`, `tests/`, `tools/`, `openspec/`（不含隐藏目录）
- 构建和测试正常通过
