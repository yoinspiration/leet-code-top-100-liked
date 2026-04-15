# 22. 括号生成

https://leetcode.cn/problems/generate-parentheses/

## 题目

数字 `n` 代表生成括号的对数，生成所有可能的**有效**括号组合。

**示例：**
```
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
```

## 思路：回溯

用 `open`、`close` 分别记录已放的左右括号数，两条规则保证合法性：

- `open < n`：还可以放左括号
- `close < open`：右括号不能超过左括号，才可以放右括号

```
n=2
backtrack(open=0, close=0, path="")
  放( → backtrack(open=1, close=0, path="(")
    放( → backtrack(open=2, close=0, path="((")
      放) → backtrack(open=2, close=1, path="(()")
        放) → backtrack(open=2, close=2, path="(())") → 记录
    放) → backtrack(open=1, close=1, path="()")
      放( → backtrack(open=2, close=1, path="()(")
        放) → backtrack(open=2, close=2, path="()()") → 记录
```

与组合总和的区别：
- 不是在数组里选元素，而是在每步**二选一**（放左括号或右括号）
- 条件本身就是剪枝，不合法的分支根本不会进入递归

## 实现

- [回溯](Backtracking.cpp)

## 复杂度

- 时间：O(4ⁿ / √n)，即第 n 个卡特兰数
- 空间：O(n)，递归栈深度
