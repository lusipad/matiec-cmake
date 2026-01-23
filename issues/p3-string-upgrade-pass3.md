# P3：字符串处理升级（Pass3）

目标：在 Pass2 的基础上，补齐 `stage1_2`（Flex/Bison）里残留的 `strcmp` 比较，统一用更安全/更直接的字面量判断方式，避免无谓的 C 字符串比较调用；保持现有行为与输出不变。

非目标（本次不做）：
- 不做 `token_c` 内部存储从 `char*` 向 `std::string` 的大迁移（范围更大，需要单独拆分）。
- 不改语法/词法规则的语义，只做比较方式改造。

## E2E loop
1) plan → issues：见 `issues/p3-string-upgrade-pass3.csv`
2) implement：按 issue 优先级逐个小提交（每个 issue 一个 commit）
3) test：每个 code issue 至少 Windows Release build + `ctest`
4) review：重点检查：
   - Flex/Bison 生成代码可正常编译（本地 build 会自动触发生成）
   - 比较语义不变（`yytext` 单字符规则、unknown file 过滤）
5) commit：按 issue 粒度提交，方便回滚
6) regression：Windows 全量 ctest + CI（linux-x64-sanitizers）通过

## 默认验证命令
- Windows：`cmake --build build-vs --config Release`；`ctest --test-dir build-vs -C Release --output-on-failure`
- CI：GitHub Actions `linux-x64-sanitizers`（ASan+LSan detect_leaks=1）

## 风险
- Flex/Bison 属于编译链路入口：虽然改动极小，但会触发重新生成，需依赖本地与 CI 门禁兜底。

## 回滚/安全
- 每个 issue 独立 commit；可按 commit 粒度 `git revert <sha>` 回滚。
- 不引入对外行为变更；仅替换比较实现方式。

