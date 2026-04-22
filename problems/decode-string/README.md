# Decode String

## 解法：栈 [Stack.cpp](Stack.cpp)

### 算法思路

用两个栈模拟括号嵌套：

- `numSt`：保存待重复的次数
- `strSt`：保存进入 `[` 之前已构建的字符串
- `cur`：当前层正在构建的字符串
- `num`：当前正在读取的数字（支持多位数）

遍历每个字符：

| 字符 | 操作 |
|------|------|
| 数字 | `num = num * 10 + digit`（处理多位数） |
| `[`  | 将 `num` 和 `cur` 压栈，重置两者 |
| `]`  | 弹出次数和前缀串，将 `cur` 重复拼接后赋回 `cur` |
| 字母 | `cur += c` |

以 `"3[a2[c]]"` 为例：

```
遇到 3       → num=3
遇到 [       → numSt:[3], strSt:[""], cur="", num=0
遇到 a       → cur="a"
遇到 2       → num=2
遇到 [       → numSt:[3,2], strSt:["","a"], cur="", num=0
遇到 c       → cur="c"
遇到 ]       → repeat=2, prev="a", cur="a"+"c"+"c"="acc"
遇到 ]       → repeat=3, prev="",  cur=""+"acc"*3="accaccacc"
```

### 复杂度分析

- **时间复杂度：O(n × k)**，n 为输出串长度，k 为最大重复次数
- **空间复杂度：O(n)**，栈的深度与嵌套层数成正比
