# Bomblab

This is the Readme for CSAPP Bomblab
The goal is mainly for u to be familiar with assembly language

# Using tools

##gdb
gdb ./bomb
(gdb) x/s 0x402400 etc

##objdump
objdump -d bomb | grep -A 40 "<phase_1>:"
objdump -s -j .rodata bomb
objdump -t bomb | grep phase

# Main Idea of each phase

##phase 1
字符串比较

##phase 2
数组循环

##phase 3
switch 跳转表

##phase 4
二分递归

##phase 5
字符低 4 位作索引查表 |映射-掩码取低位索引-查表-返回

##phase 6
链表重排 + 排序 |输入 1~6 排列 → 作节点索引取链表节点 → 重排 → 按节点值降序返回
