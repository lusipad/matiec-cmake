# P2：内存安全护栏（Sanitizers）Pass2（LeakSanitizer 清理）

目标：在不改变默认构建行为的前提下，逐步修复 LeakSanitizer（LSan）在测试/编译路径上暴露的真实内存泄漏，最终恢复 CI 的 `detect_leaks=1` 门禁。

非目标：
- 不在本 pass 内做 AST/Stage 的“架构级所有权重写”（那属于更高风险的 P2 专项）。
- 不承诺一次性清零所有泄漏：优先修复可复现、影响 CI 的泄漏；剩余部分按发现再拆分 Issue。

## 步骤（E2E loop）
1) plan → issues：见 `issues/p2-memory-safety-guardrails-pass2.csv`
2) implement：按 issue 粒度小步修复泄漏（优先用 RAII/unique_ptr/栈对象）
3) test：用 `ASAN_OPTIONS=detect_leaks=1` 复现并验证修复；保持默认构建/测试不受影响
4) review：确认无行为变化；确认修复不引入悬垂指针/二次释放
5) commit：尽量一 issue 一提交，便于回滚
6) regression：在 LSan 下跑一组关键测试；在默认构建下跑全量 `ctest`

## 默认验证命令（本机示例）
- WSL（ASan+LSan，单测复现）：`ASAN_OPTIONS=detect_leaks=1 ctest --test-dir build-wsl-asan -R <test> --output-on-failure`
- Windows（默认 Release）：`ctest --test-dir build-vs -C Release --output-on-failure`

## 风险
- 泄漏可能来自 flex/bison 或历史全局状态，修复需要谨慎验证不破坏多次编译/错误恢复路径。
- 在 CI 恢复 LSan 之前，可能需要多个小 issue 逐步清零。

## 回滚/安全
- 每个修复尽量是局部、可回滚的小提交；必要时可 `git revert <commit>` 回退。

