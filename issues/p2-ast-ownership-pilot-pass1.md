# P2：AST 所有权/unique_ptr 试点 Pass1

目标：在不大改 AST 节点所有权模型的前提下，先把“编译级资源（AST roots + lexer 字符串池 + 全局状态）”的生命周期管理明确化、可复用化，并用 `std::unique_ptr`/RAII 覆盖所有退出路径（含 early return/异常）。

非目标：
- 不在本 pass 内对 AST 节点结构做大规模 `unique_ptr` 化（例如 `SYM_REF*` 成员、`list_c` 元素）。
- 不改变 public C API 的签名与行为。
- 不做全库格式化或纯风格重排。

## 步骤（E2E loop）
1) plan → issues：见 `issues/p2-ast-ownership-pilot-pass1.csv`
2) implement：
   - E1：补充 AST 生命周期/所有权设计文档（中文）
   - E2：提取并复用 `compilation_cleanup_guard`（先用于 C API）
   - E3：`main.cc` 也改为使用同一 guard，保持行为不变
3) test：每个 code issue 至少 Windows Release build + `ctest`
4) review：重点检查清理顺序/早退路径/异常路径是否一致；避免双重释放/漏清理
5) commit：按 issue 粒度小提交
6) regression：执行 E4，并依赖 CI 验证（含 Sanitizers + LSan 门禁）

## 默认验证命令
- Windows：`cmake --build build-vs --config Release`；`ctest --test-dir build-vs -C Release --output-on-failure`
- WSL（ASan+LSan）：`ASAN_OPTIONS=detect_leaks=1 ctest --test-dir build-wsl-asan --output-on-failure`

## 风险
- 清理顺序错误可能导致 use-after-free（例如先释放 AST 再清理引用 AST 的全局表）。
- 不同入口（CLI/C API）清理策略不一致可能导致“库调用多次”场景下的隐性泄漏或崩溃。

## 回滚/安全
- 每个 issue 独立 commit，可逐个 `git revert <sha>` 回滚；默认行为不改。

