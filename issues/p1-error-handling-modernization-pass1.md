# P1：错误处理现代化 第 1 轮（Stage3 诊断试点）

目标：在不改变现有 stderr 输出格式与错误计数行为的前提下，抽取 stage3 诊断桥接逻辑为公共 helper，并在 array_range_check / case_elements_check 试点；补充 C API 语义错误信息的单元测试，确保错误细节可被结构化读取。

非目标：
- 不改动 CLI 的输出策略（仍打印到 stderr）。
- 不改动 stage1_2 / stage4 的诊断路径。
- 不改动 ErrorReporter 的存储结构（派生错误切片问题留到后续）。

## 步骤（E2E loop）
1) plan → issues：生成 Issue CSV（A1-A2）。
2) implement：新增 stage3 诊断 helper，替换试点文件的宏；补充 C API 语义错误测试。
3) test：构建 + 相关测试（test_matiec_api）。
4) review：对比诊断输出格式与错误计数行为，确认无回归。
5) commit：按 issue 粒度提交（若需要）。
6) regression：本轮全部完成后再跑全量 ctest。

## 验证方法
- 构建：cmake --build build-vs --config Release
- 测试：ctest --test-dir build-vs -C Release -R test_matiec_api --output-on-failure

## 风险
- 诊断输出格式与既有 stderr 输出存在细微差异（需对齐原格式）。
- 抽取公共 helper 时可能遗漏某些 file/line 字段，导致错误定位回退。

## 回滚 / 安全
- 每个 issue 独立回滚（git revert <commit>）。
- 不涉及数据迁移；保持相同输入产生相同行为与输出。
