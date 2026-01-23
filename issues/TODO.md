# TODO List（按优先级）
说明：本仓库使用 Issue CSV 作为每个 plan 的“执行契约”，字段含义与格式要求见 `issues/README.md`。本清单用于快速导航；以 CSV 中的状态为准。

## 进行中
- P3 回归收尾：`issues/p3-string-upgrade-pass1.csv` 的 `S5`（等待 CI linux-x64-sanitizers/LSan 门禁通过）

## 下一步（按优先级）
1) 等 CI 通过后，把 `issues/p3-string-upgrade-pass1.csv` 的 `S5`：`Review1_Status`/`Regression_Status` 置为 `DONE`，并在 `Notes` 记录 run 链接/编号
2) 如需继续推进 P3 后续（Pass2+）：先做“小范围替换清单 + 回归门禁”，避免直接动 Bison `%union`（高风险）

## 已完成（DONE）
- `issues/p-modern-cpp-style-overview.csv`：M1-M8
- `issues/p2-memory-safety-guardrails-pass1.csv`：B1-B3
- `issues/p2-memory-safety-guardrails-pass2.csv`：C1-C3
- `issues/p2-stage4-raii-pass1.csv`：A1-A4
- `issues/p2-raii-sweep-pass2.csv`：D1-D4
- `issues/p2-ast-ownership-pilot-pass1.csv`：E1-E4
- `issues/p3-string-upgrade-pass1.csv`：S1-S4（待回归 S5）
