# P2：Stage4 RAII 第 1 轮

目标：在不改变生成代码行为的前提下，把 stage4 C 代码生成器里“明确所有权”的 `new`/`delete` 改成 RAII（`std::unique_ptr` 或栈对象），降低内存与异常路径风险。

非目标：
- 不处理 C API 的输出格式选择（C vs IEC）问题（单独跟踪）。
- 不做 stage4 生成器架构级大重构。

## 步骤（E2E loop）
1) plan → issues：范围仅限 stage4 C 生成器“所有权清晰”的清理（A1-A4）。
2) implement：按 issue 顺序逐个落地；每个 issue 保持小改动、可 review。
3) test（每个 issue）：编译 + 运行对应测试。
4) review：自检所有权/生命周期与行为一致性（输出不变）。
5) commit：原则上一 issue 一提交（或同一问题点的紧耦合文件一提交）。
6) regression：所有 issue DONE 后，跑一次完整测试回归。

## 验证方法
- 构建：`cmake --build build-vs --config Release`
- 测试：`ctest --test-dir build-vs -C Release --output-on-failure`

## 风险
- 生命周期变化：若某些 helper 之前“意外”依赖堆分配跨作用域存活，改为栈对象可能暴露问题（本轮选择的点预期不会）。
- 异常路径：确保 RAII 的析构/unique_ptr 清理逻辑与原 `delete` 等价。

## 回滚 / 安全
- 每个 issue 独立，可用 `git revert <commit>` 回滚。
- 无数据迁移；同一输入应生成相同输出。
