# Permutations

全排列

## 题目要求

给定一个**不含重复数字**的整数数组 `nums`，返回其所有可能的全排列。

题目链接：[46. 全排列](https://leetcode.cn/problems/permutations/)

## 解法：回溯 [Backtracking.cpp](Backtracking.cpp)

用 `used[i]` 标记第 `i` 个元素是否已在当前路径中。每层枚举所有未使用的元素，选一个加入路径后递归，递归返回后撤销（回溯）。

```
permute([1,2,3])

选 1 → 选 2 → 选 3 → [1,2,3] ✓
      ← 撤 3 → 选 3 → 选 2 → [1,3,2] ✓
选 2 → 选 1 → 选 3 → [2,1,3] ✓
      ...
```

**回溯三要素：**
- **选择**：`used[i] = true; path.push_back(nums[i])`
- **递归**：`backtrack(...)`
- **撤销**：`path.pop_back(); used[i] = false`

- **时间复杂度：O(n × n!)**，共 n! 个排列，每个需 O(n) 复制到结果。
- **空间复杂度：O(n)**，递归栈 + path + used 均为 O(n)。
