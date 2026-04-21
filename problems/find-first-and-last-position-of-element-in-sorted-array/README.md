# Find First and Last Position of Element in Sorted Array

## 解法：二分查找 [BinarySearch.cpp](BinarySearch.cpp)

### 算法思路

对目标值做两次二分，复用同一个 `lowerBound` 辅助函数：

- **左边界**：找第一个 `>= target` 的下标
- **右边界**：找第一个 `>= target + 1` 的下标减一

若左边界越界或对应值不等于 `target`，说明目标不存在，返回 `[-1, -1]`。

### 复杂度分析

- **时间复杂度：O(log n)**
- **空间复杂度：O(1)**
