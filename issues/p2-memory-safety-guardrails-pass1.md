# P2：内存安全护栏（Sanitizers）Pass1

目标：在不改变默认构建行为的前提下，引入“可选”的 Sanitizers（ASan/UBSan）构建与 CI 运行，用于尽早暴露潜在的内存/未定义行为问题，为后续 P2 内存管理改造提供护栏。

非目标：
- 不在本 pass 内修复所有被 Sanitizers 暴露的问题（先建立护栏与可复现入口）。
- 不强制所有平台启用（默认 OFF；CI 仅在 Linux 上启用一条 Job）。

## 步骤（E2E loop）
1) plan → issues：见 `issues/p2-memory-safety-guardrails-pass1.csv`
2) implement：
   - CMake：增加 `MATIEC_ENABLE_SANITIZERS`（默认 OFF），并在支持的编译器上注入 `-fsanitize=...` 相关编译/链接参数
   - CI：Linux x64 增加一条启用 Sanitizers 的构建与测试 Job
   - 文档：补充本地如何启用 Sanitizers 的命令
3) test：按 Issue CSV 的 Test_Method 执行（至少确保默认构建 + 全量 ctest 通过）
4) review：确认默认 OFF 不引入工具链耦合；确认 Windows/MSVC 下不会误注入 clang/gcc flags
5) commit：尽量按 issue 粒度提交
6) regression：跑全量 `ctest`（默认配置），并依赖 CI 验证 sanitizer job

## 默认验证命令
- 构建：`cmake --build build-vs --config Release`
- 测试：`ctest --test-dir build-vs -C Release --output-on-failure`

## 风险
- Sanitizers flags 在某些编译器/平台组合下不兼容（尤其是 Windows + clang-cl/MSVC）。
- CI 时间增加（新增一个 job）。

## 回滚/安全
- 默认 OFF；如需回滚可 `git revert <commit>`。

