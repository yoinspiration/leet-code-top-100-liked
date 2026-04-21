# Search in Rotated Sorted Array

## 解法：二分查找 [BinarySearch.cpp](BinarySearch.cpp)

### 算法思路

旋转数组的关键性质：以 `mid` 为界，**左半段或右半段必有一段是严格有序的**。

每次二分时先判断哪半段有序：

- 若 `nums[left] <= nums[mid]`，左半段有序：
  - target 在 `[nums[left], nums[mid])` 内 → 收缩右边界
  - 否则 → 收缩左边界
- 否则右半段有序：
  - target 在 `(nums[mid], nums[right]]` 内 → 收缩左边界
  - 否则 → 收缩右边界

### 复杂度分析

- **时间复杂度：O(log n)**
- **空间复杂度：O(1)**
