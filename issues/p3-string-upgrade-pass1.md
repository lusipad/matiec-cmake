# P3：字符串处理升级（Pass1）

目标：在不破坏现有对外行为（CLI / C API / 生成代码）的前提下，完成编译器内部字符串处理的现代化（C++17），降低 UB/溢出/编码与平台差异风险，并把相关改造纳入可回归的测试与 CI 门禁。

非目标（本次不做）：
- 不修改 IEC 运行时库里 `STR_MAX_LEN` 等字符串类型长度语义（这属于运行时/代码生成语义变更，需单独评审与兼容策略）。
- 不进行全仓库“机械式大改”（避免巨型 diff）。

## E2E loop
1) plan → issues：见 `issues/p3-string-upgrade-pass1.csv`
2) implement：按 issue 优先级逐个小提交（每个 issue 一个 commit）
3) test：每个 code issue 至少 Windows Release build + `ctest`
4) review：重点检查：
   - `std::string_view` 与 `const char*` 的边界（尤其是 NULL/空串语义）
   - case-insensitive 比较的正确性（避免把 “less-than comparator” 当成 “equal”）
   - Windows/WSL/macOS 的路径与临时文件行为一致性
5) commit：按 issue 粒度提交，方便回滚
6) regression：全量回归 + Sanitizers + CI

## 默认验证命令
- Windows：`cmake --build build-vs --config Release`；`ctest --test-dir build-vs -C Release --output-on-failure`
- WSL（ASan+LSan）：`ASAN_OPTIONS=detect_leaks=1 ctest --test-dir build-wsl-asan --output-on-failure`

## 风险
- 解析器/AST 属于编译链路核心：字符串语义改动可能导致 subtle 行为差异（如大小写比较、NULL/空串处理）。
- Windows 临时文件生成策略改动可能引入权限/路径/清理差异。

## 回滚/安全
- 每个 issue 独立 commit；可按 commit 粒度 `git revert <sha>` 回滚。
- 默认保持 ABI/API 与既有输出语义不变；若必须变更，在 issue Notes 里记录并补充测试覆盖。

