# 17. 电话号码的字母组合

https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

## 题目

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合（九宫格键盘映射）。

```
2→abc  3→def  4→ghi  5→jkl
6→mno  7→pqrs 8→tuv  9→wxyz
```

**示例：**
```
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

## 思路：回溯

与子集/全排列的区别：
- 不是从数组中选元素，而是**按位**依次从键盘映射中选一个字母
- 用 `index` 表示当前处理第几位数字，递归时 `index + 1`
- 路径长度等于 `digits` 长度时记录结果

```
digits = "23"
backtrack(index=0, path="")
  取'a' → backtrack(index=1, path="a")
    取'd' → backtrack(index=2, path="ad") → 记录 "ad"
    取'e' → backtrack(index=2, path="ae") → 记录 "ae"
    取'f' → backtrack(index=2, path="af") → 记录 "af"
  取'b' → backtrack(index=1, path="b")
    ...
```

- **终止条件**：`index == digits.size()`，记录路径
- **撤销**：`path.pop_back()` 换下一个字母

## 实现

- [回溯](Backtracking.cpp)

## 复杂度

- 时间：O(4ⁿ × n)，n 为数字个数，每位最多 4 个字母（7、9）
- 空间：O(n)，递归栈深度
