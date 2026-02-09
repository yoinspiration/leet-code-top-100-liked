# LeetCode Top 100 Liked

LeetCode 热题 100

## 题目列表

### 哈希

- [Two Sum](two-sum/README.md) - 两数之和
  - [暴力枚举](two-sum/BruteForce.cpp) O(n²)
  - [哈希表](two-sum/HashTable.cpp) O(n)
- [Group Anagrams](group-anagrams/README.md) - 字母异位词分组
  - [哈希表](group-anagrams/HashTable.cpp) O(n \* k log k)
- [Longest Consecutive Sequence](longest-consecutive-sequence/README.md) - 最长连续序列
  - [哈希集合](longest-consecutive-sequence/HashSet.cpp) O(n)
- [Subarray Sum Equals K](subarray-sum-equals-k/README.md) - 和为 K 的子数组
  - [暴力枚举](subarray-sum-equals-k/BruteForce.cpp) O(n²)
  - [前缀和+哈希表](subarray-sum-equals-k/PrefixSum.cpp) O(n)

### 双指针

- [Move Zeroes](move-zeroes/README.md) - 移动零
  - [暴力枚举](move-zeroes/BruteForce.cpp) O(n²)
  - [双指针](move-zeroes/TwoPointers.cpp) O(n)
- [Container With Most Water](container-with-most-water/README.md) - 盛最多水的容器
  - [暴力枚举](container-with-most-water/BruteForce.cpp) O(n²)
  - [双指针](container-with-most-water/TwoPointers.cpp) O(n)
- [3Sum](3sum/README.md) - 三数之和
  - [暴力枚举](3sum/BruteForce.cpp) O(n³)
  - [排序+双指针](3sum/TwoPointers.cpp) O(n²)
- [Trapping Rain Water](trapping-rain-water/README.md) - 接雨水
  - [双指针](trapping-rain-water/TwoPointers.cpp) O(n)
  - [动态规划](trapping-rain-water/DynamicProgramming.cpp) O(n)
- [Intersection of Two Linked Lists](intersection-of-two-linked-lists/README.md) - 相交链表
  - [双指针对齐长度](intersection-of-two-linked-lists/TwoPointers.cpp) O(m + n)
- [Reverse Linked List](reverse-linked-list/README.md) - 反转链表
  - [迭代反转](reverse-linked-list/Iterative.cpp) O(n)
 - [Palindrome Linked List](palindrome-linked-list/README.md) - 回文链表
   - [快慢指针+反转后半段](palindrome-linked-list/TwoPointers.cpp) O(n)
 - [Linked List Cycle](linked-list-cycle/README.md) - 环形链表
   - [快慢指针](linked-list-cycle/Floyd.cpp) O(n)

### 滑动窗口

- [Longest Substring Without Repeating Characters](longest-substring-without-repeating-characters/README.md) - 无重复字符的最长子串
  - [暴力枚举](longest-substring-without-repeating-characters/BruteForce.cpp) O(n²)
  - [滑动窗口](longest-substring-without-repeating-characters/SlidingWindow.cpp) O(n)
- [Find All Anagrams in a String](find-all-anagrams-in-a-string/README.md) - 找到字符串中所有字母异位词
  - [滑动窗口](find-all-anagrams-in-a-string/SlidingWindow.cpp) O(n)
- [Sliding Window Maximum](sliding-window-maximum/README.md) - 滑动窗口最大值
  - [暴力枚举](sliding-window-maximum/BruteForce.cpp) O(n * k)
  - [单调队列](sliding-window-maximum/MonotonicQueue.cpp) O(n)
 - [Minimum Window Substring](minimum-window-substring/README.md) - 最小覆盖子串
   - [滑动窗口](minimum-window-substring/SlidingWindow.cpp) O(|s| + |t|)

### 动态规划

- [Maximum Subarray](maximum-subarray/README.md) - 最大子数组和
  - [暴力枚举](maximum-subarray/BruteForce.cpp) O(n²)
  - [动态规划](maximum-subarray/DynamicProgramming.cpp) O(n)

### 排序

- [Merge Intervals](merge-intervals/README.md) - 合并区间
  - [排序](merge-intervals/Sorting.cpp) O(n log n)

### 数组

- [First Missing Positive](first-missing-positive/README.md) - 缺失的第一个正数
  - [原地哈希](first-missing-positive/InPlaceHash.cpp) O(n)
- [Product of Array Except Self](product-of-array-except-self/README.md) - 除自身以外数组的乘积
  - [前缀积+后缀积](product-of-array-except-self/PrefixProduct.cpp) O(n)
- [Rotate Array](rotate-array/README.md) - 轮转数组
  - [使用额外数组](rotate-array/ExtraArray.cpp) O(n)
  - [三次反转](rotate-array/ThreeReversals.cpp) O(n)
- [Set Matrix Zeroes](set-matrix-zeroes/README.md) - 矩阵置零
  - [原地标记](set-matrix-zeroes/InPlace.cpp) O(m × n)
- [Spiral Matrix](spiral-matrix/README.md) - 螺旋矩阵
  - [模拟法](spiral-matrix/Simulation.cpp) O(m × n)
- [Rotate Image](rotate-image/README.md) - 旋转图像
  - [转置+翻转](rotate-image/TransposeAndReverse.cpp) O(n²)
- [Search a 2D Matrix II](search-a-2d-matrix-ii/README.md) - 搜索二维矩阵 II
  - [从角落搜索](search-a-2d-matrix-ii/SearchFromCorner.cpp) O(m + n)