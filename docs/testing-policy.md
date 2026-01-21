# 测试策略（Testing Policy）

目的：为改造提供最小、可靠、可重复的验证方式，避免“改了但没测/测了但没说清”。

## 基本原则
- 默认优先跑最窄测试以证明改动正确；若改动风险较高，再扩大到完整回归。
- 任何情况下：未运行的测试不要声称已运行（可以说明“未运行/原因/风险”）。

## 默认验证命令（Windows / VS build dir）
- 构建：`cmake --build build-vs --config Release`
- 测试：`ctest --test-dir build-vs -C Release --output-on-failure`

## 何时跑哪些测试（建议）
- 仅文档/注释变更：可不跑测试（在提交信息或 Issue Notes 里说明“doc-only”）。
- 仅局部实现变更（低风险）：构建 + `ctest`（可用 `ctest -R <regex>` 先跑相关用例）。
- 影响编译/链接/入口路径/全局状态（中高风险）：构建 + 全量 `ctest`。
- 大范围重构或行为语义变更：构建 + 全量 `ctest`；必要时补充 E2E/输出断言。

