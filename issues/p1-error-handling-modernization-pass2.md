# P1：错误处理现代化 第 2 轮（全项目）

目标：在不改变现有 stderr 输出格式与错误计数语义的前提下，完成全项目诊断路径现代化：
- stage1_2（lexer/parser）与 stage3、stage4 的错误统一上报 ErrorReporter；
- ErrorReporter 细节保留（避免派生切片），C API 读取更完整错误信息；
- 关键路径补充单元测试（语义/代码生成错误）。

非目标：
- 不改动运行时库（lib/C）与测试脚本的输出行为（除非直接影响编译器错误链路）。
- 不改变现有错误消息文本与格式（仅修正结构化上报）。

## 步骤（E2E loop）
1) plan → issues：生成本轮 Issue CSV（B1-B4）。
2) implement：按 issue 顺序小步落地，保持可回滚。
3) test：先最小验证（build + 相关 ctest），必要时补全。
4) review：对比 stderr 格式与 error_count 行为是否一致。
5) commit：每个 issue 独立提交（Angular 规范）。
6) regression：所有 issue 完成后跑全量 ctest。

## 验证方法
- 构建：cmake --build build-vs --config Release
- 单测：ctest --test-dir build-vs -C Release -R MatiecApiTest --output-on-failure
- 回归：ctest --test-dir build-vs -C Release --output-on-failure

## 风险
- 诊断输出格式细微变化导致基线差异。
- C API 结构化错误读取路径变化带来兼容性回归。
- Windows build-vs 环境与 WSL 路径差异导致构建失败。

## 回滚 / 安全
- 每个 issue 独立提交，可 git revert <commit>。
- 不涉及数据迁移，保持相同输入产生相同行为与输出。
