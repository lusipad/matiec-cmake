# P1：build-vs 警告收敛 Pass1

目标：在不改变运行时语义的前提下，消除 build-vs 当前可复现的编译警告（MSVC C4005/C4267/C4244/C4146/C4101/C4834）。

范围（本轮）：
- stage1_2：flex 生成文件的宏重定义预防、tracking 的 size_t→int 显式转换。
- stage3/util：窄化转换与 unsigned 负号警告的显式处理。
- stage4/generate_c：count 的 size_t→int、未使用变量、实数到整数的显式转换。
- tests：[[nodiscard]] 返回值处理。

非目标：
- 不变更编译器行为/输出（仅补充显式转换或去掉未使用变量）。
- 不处理外部工具链或第三方库导致的警告。

## 步骤（E2E loop）
1) plan → issues：生成 Issue CSV（W1-W4）。
2) implement：按 W1→W4 小步提交。
3) test：build-vs，必要时全量 ctest。
4) review：确认警告收敛且行为一致。
5) commit：每个 issue 独立提交（Angular 规范）。
6) regression：全量 ctest（或同等回归）。

## 验证方法
- 构建：`cmake --build build-vs --config Release`
- 回归：`ctest --test-dir build-vs -C Release --output-on-failure`

## 风险
- 显式窄化转换隐藏潜在溢出路径（但保持与现有隐式转换一致）。
- flex 顶部 include 调整可能影响生成文件宏定义顺序。

## 回滚 / 安全
- 每个 issue 独立提交，可 `git revert <commit>` 回退单步。
