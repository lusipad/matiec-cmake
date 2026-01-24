# 性能回归检查清单

目标：为代码生成相关改动提供可重复的性能回归记录方式。

## 前置条件
- 已完成构建：`cmake --build build-wsl`
- 工具可用：`build-wsl/iec2c` 与 `build-wsl/iec2iec`
- 固定输入：`tests/fixtures/simple_program.st`

## 建议流程（WSL / Linux）
1) 准备输出目录（避免与历史混用）：
   `mkdir -p tmp/perf-run`
2) 预热一次（丢弃结果）：
   `./build-wsl/iec2c -I lib -T tmp/perf-run tests/fixtures/simple_program.st >/dev/null`
   `./build-wsl/iec2iec -I lib tests/fixtures/simple_program.st >/dev/null`
3) 计时采样（示例：5 次，记录 real 秒数）：
   `for i in 1 2 3 4 5; do /usr/bin/time -f "%e" ./build-wsl/iec2c -I lib -T tmp/perf-run tests/fixtures/simple_program.st >/dev/null; done`
   `for i in 1 2 3 4 5; do /usr/bin/time -f "%e" ./build-wsl/iec2iec -I lib tests/fixtures/simple_program.st >/dev/null; done`
4) 记录环境信息（CPU / OS / 编译器版本）与均值/中位数。

## Windows 参考
- PowerShell 可用 `Measure-Command` 进行计时。
- 建议在固定 Release 构建、关闭后台重负载后重复采样。
