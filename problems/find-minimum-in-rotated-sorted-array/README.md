# Find Minimum in Rotated Sorted Array

## 解法：二分查找 [BinarySearch.cpp](BinarySearch.cpp)

### 算法思路

将 `nums[mid]` 与 `nums[right]` 比较：

- `nums[mid] > nums[right]`：mid 在左段，最小值在右半部分 → `left = mid + 1`
- `nums[mid] <= nums[right]`：mid 在右段，最小值在左半部分（含 mid）→ `right = mid`

循环结束时 `left == right`，即为最小值下标。

### 复杂度分析

- **时间复杂度：O(log n)**
- **空间复杂度：O(1)**
