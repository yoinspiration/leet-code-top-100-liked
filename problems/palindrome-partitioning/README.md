# 131. 分割回文串

https://leetcode.cn/problems/palindrome-partitioning/

## 题目

给你一个字符串 `s`，请你将 `s` 分割成一些子串，使每个子串都是**回文串**。返回 `s` 所有可能的分割方案。

**示例：**
```
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
```

## 思路：回溯

从左到右枚举当前这一段的结束位置：

- 如果 `s[start..end]` 不是回文串，当前切法直接跳过
- 如果是回文串，就把它加入路径，继续处理下一段 `end + 1`
- 当 `start` 走到字符串末尾时，说明整串已经被合法分割，记录当前路径

```
backtrack(start=0, path=[])
  选 "a"  -> backtrack(start=1, path=["a"])
    选 "a" -> backtrack(start=2, path=["a","a"])
      选 "b" -> 记录 ["a","a","b"]
    选 "ab" 不是回文，跳过
  选 "aa" -> backtrack(start=2, path=["aa"])
    选 "b" -> 记录 ["aa","b"]
  选 "aab" 不是回文，跳过
```

- `start` 表示当前要切分的位置
- `isPalindrome(left, right)` 用双指针判断这一段是否为回文
- 回溯返回时用 `path.pop_back()` 撤销本次选择

## 实现

- [回溯](Backtracking.cpp)

## 复杂度

- 时间：O(n × 2^n)，最多有 `2^(n-1)` 种切分方式，每次判断/构造路径还要消耗 O(n)
- 空间：O(n)，递归栈与当前路径长度
