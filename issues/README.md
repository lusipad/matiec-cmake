# Issue CSV 规则

本仓库使用 Issue CSV 作为每个 plan 的“执行契约”（execution contract）。

## 必填列
所有列都必须存在且必须填写（不可留空）：
- ID：唯一 issue ID（A1, A2, ...）
- Title：短标题
- Description：范围/边界（做什么、不做什么）
- Acceptance：完成标准（done criteria）
- Test_Method：验证方式（工具、命令或手工步骤）
- Tools：要使用的 MCP/tool（或 "manual"/"none"）；可用的 MCP 工具名见 `docs/mcp-tools.md`
- Dev_Status：TODO | DOING | DONE
- Review1_Status：TODO | DOING | DONE
- Regression_Status：TODO | DOING | DONE
- Files：涉及的文件路径或范围（若不适用，用 sentinel 值）
- Dependencies：依赖的其它 ID 或外部依赖（无则写 "none"）
- Notes：补充说明（无则写 "none"）

## Sentinel 值
当字段必填但“不适用”时使用：
- Files：N/A | external | TBD | module:<name> | <glob>
- Dependencies：none
- Notes：none
- Tools：manual | none

## Test_Method 指南
每个 issue 必须明确“如何验证”。优先使用最窄、但足够可靠的方法：
- Unit / Integration：若已有测试框架且改动偏逻辑，优先用单元/集成测试。
- API / Contract：服务端/库接口改动，用可复现的命令或脚本验证（如 curl/Postman/自研脚本）。
- UI / E2E：前端流程，用 E2E 工具验证（如 Playwright/Chrome DevTools MCP）。
- Manual：仅在自动化不可行时使用；必须写清楚可复现的步骤。

Review 状态含义：
- Review1_Status：该 issue 实现完成后的验证状态。
- Regression_Status：同一批 issue 全部完成后的回归验证状态（全量/冒烟）。
只有在声明的 Test_Method 实际执行并通过后，才能把 Review1/Regression 标为 DONE；若只能手工或不可执行，必须在 Notes 里记录原因与风险。

## CSV 格式要求
- 字段中包含英文逗号 `,` 时，用英文双引号 `"` 包裹该字段。
- 同一字段内需要列多个值时，用 `|` 分隔。

## 示例行
ID,Title,Description,Acceptance,Test_Method,Tools,Dev_Status,Review1_Status,Regression_Status,Files,Dependencies,Notes
A1,Login error handling,"Handle invalid token in /auth/login","Returns 401 + error code","AUTOCURL mock token",AUTOCURL,TODO,TODO,TODO,"src/auth/login.ts | src/auth/token.ts",none,none
