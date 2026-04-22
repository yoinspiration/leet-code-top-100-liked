# Median of Two Sorted Arrays

## 解法一：暴力合并排序 [BruteForce.cpp](BruteForce.cpp)

### 算法思路

将两个数组合并后排序，直接取中位数。

### 复杂度分析

- **时间复杂度：O((m+n) log(m+n))**
- **空间复杂度：O(m+n)**

## 解法二：二分查找 [BinarySearch.cpp](BinarySearch.cpp)

### 算法思路

核心思想：对较短的数组做二分，寻找一个合法的**切割位置**，使两数组左半部分的最大值 ≤ 右半部分的最小值。

设 `m = nums1.size()`，`n = nums2.size()`，且 `m ≤ n`。

在 `nums1` 的 `[0, m]` 范围上二分，设切割点为 `i`，则 `nums2` 的切割点为 `j = (m+n+1)/2 - i`。

切割点 `i` 将 `nums1` 分为左侧 `nums1[0..i-1]` 和右侧 `nums1[i..m-1]`，`j` 同理分割 `nums2`。合法切割满足：

```
maxLeft1 <= minRight2  &&  maxLeft2 <= minRight1
```

- 若 `maxLeft1 > minRight2`：`i` 偏大，令 `right = i - 1`
- 若 `maxLeft2 > minRight1`：`i` 偏小，令 `left = i + 1`

找到合法切割后：
- 总长度为奇数：中位数 = `max(maxLeft1, maxLeft2)`
- 总长度为偶数：中位数 = `(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0`

边界处理：当 `i=0` 时 `maxLeft1 = INT_MIN`，当 `i=m` 时 `minRight1 = INT_MAX`，`j` 同理。

### 复杂度分析

- **时间复杂度：O(log(min(m, n)))**，只在较短数组上二分
- **空间复杂度：O(1)**
