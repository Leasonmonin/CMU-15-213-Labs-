# Datalab

This is the Readme for CSAPP datalab

# Main ideas of all puzzles

##位运算相关问题 -根据目标条件构造掩码比较 通过 & | ~ ^ 位运算 清零或是保留 -分类讨论 通过用掩码进行选择实现if-else思路 -灵活应用补码的性质 `-x = ~x+1 `;`Tmax = Tmin-1` etc -适时取符号位辅助解题 通过移位运算实现 形如`x >> 31`

##浮点数相关问题

-围绕IEEE 754 的 `S | E | Frac` 三段结构展开；

-熟悉阶码偏置换算：`E = Exp - 127`，反之 `Exp = E + 127` -注意三种情况的边界并熟悉运用：

- 规格化数（`1 ≤ E ≤ 254`）
- 非规格化数（`E = 0`，隐含位为 0）
- NaN / Inf（`E = 255`）
