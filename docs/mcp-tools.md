# MCP 工具目录（占位）

本仓库的 Issue CSV `Tools` 列用于记录“优先使用的自动化工具/集成工具”。

## 当前约定
- 若没有明确可用的 MCP server:tool（或本环境未配置 MCP），`Tools` 填 `manual`。
- 需要 MCP 时：先确认本 session 可用的 MCP server/tool，再把 `Tools` 写成 `server:tool`，并在 Issue 的 Test_Method 里写清楚如何运行与验证。

## 说明
- Codex CLI 的内置工具（例如执行命令、打补丁）不属于 `server:tool` 形式；当仅依赖这些能力时，`Tools` 仍使用 `manual` 即可。

