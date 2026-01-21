# Modern C++ Style 概述（Issue 拆分）

目标：把“modern C++ style”相关改造拆成可执行的高层 Issue（偏概述/epic），作为后续逐步落地的执行契约入口。

说明：本文件只做概述级拆分；具体实现时，每个 epic 可以继续细化成 1 个或多个 pass 的 Issue CSV（保持“小改动、可回滚、可验证”）。

## 范围
- 工程化风格基线：代码风格规范、格式化/静态检查（默认不强制重排全库）。
- 现代 C++17 习惯用法：RAII、显式所有权、类型/资源安全、减少宏与隐式行为。
- 行为与 API 语义一致性：特别是 C API 的输出格式与错误处理行为可测试、可预期。

## 非目标
- 不做“一次性全库格式化”导致的大 diff（除非明确开启专项）。
- 不做 stage4/AST 的架构级重写（需要单独评估风险与测试护栏）。

## 执行方式（E2E loop）
1) issues：先按主题拆成概述 Issue（见 `issues/p-modern-cpp-style-overview.csv`）。
2) implement：选择 1 个 Issue，必要时先再拆成更细的 pass1 CSV，然后逐条实现。
3) test：每次落地都跑构建 + 测试；不声称未运行的验证。
4) review：自检“行为不变/接口不破坏/所有权清晰”。
5) commit：尽量一 issue 一提交，保持可回滚。
6) regression：一组相关 issue 完成后跑完整回归。

## 基础验证命令（默认）
- 构建：`cmake --build build-vs --config Release`
- 测试：`ctest --test-dir build-vs -C Release --output-on-failure`

## 风险
- 影响面较大的改造（字符串/错误处理）需要更细粒度拆分与更强测试护栏。
- 工具链相关（clang-format/clang-tidy）要确保“默认不强依赖”，避免破坏现有开发环境。

