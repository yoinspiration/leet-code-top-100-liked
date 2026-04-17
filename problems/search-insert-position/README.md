# Search Insert Position

## 解法：二分查找 [BinarySearch.cpp](BinarySearch.cpp)

### 算法思路

数组有序且元素各不相同，天然适合二分查找。

- 若 `nums[mid] == target`，直接返回 `mid`。
- 若 `nums[mid] < target`，目标在右半段，`left = mid + 1`。
- 若 `nums[mid] > target`，目标在左半段，`right = mid - 1`。

循环结束（`left > right`）时，`left` 恰好落在第一个大于 target 的位置，即插入位置。

**为什么 `left` 就是插入位置？**

循环不变量：
- `nums[0..right]` 中所有元素 ≤ target（已被排除到左侧）
- `nums[left..n-1]` 中所有元素 ≥ target（已被排除到右侧）

当 `left > right` 时，`left` 指向第一个 ≥ target 的位置，正好是应当插入的下标。

### 边界情况

| 情形 | 结果 |
|------|------|
| target < nums[0] | 返回 0 |
| target > nums[n-1] | 返回 n |
| target 存在于数组中 | 返回其下标 |
| target 在数组中间某两个元素之间 | 返回右侧元素的下标 |

### 复杂度分析

- **时间复杂度：O(log n)**
  - 每次循环将搜索范围缩小一半
- **空间复杂度：O(1)**
  - 只使用了固定数量的变量
