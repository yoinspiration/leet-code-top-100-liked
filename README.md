# LeetCode Top 100 Liked

LeetCode 热题 100

## 题目列表

### 哈希

- [Two Sum](problems/two-sum/README.md) - 两数之和
  - [暴力枚举](problems/two-sum/BruteForce.cpp) O(n²)
  - [哈希表](problems/two-sum/HashTable.cpp) O(n)
- [Group Anagrams](problems/group-anagrams/README.md) - 字母异位词分组
  - [哈希表](problems/group-anagrams/HashTable.cpp) O(n \* k log k)
- [Longest Consecutive Sequence](problems/longest-consecutive-sequence/README.md) - 最长连续序列
  - [哈希集合](problems/longest-consecutive-sequence/HashSet.cpp) O(n)
- [Subarray Sum Equals K](problems/subarray-sum-equals-k/README.md) - 和为 K 的子数组
  - [暴力枚举](problems/subarray-sum-equals-k/BruteForce.cpp) O(n²)
  - [前缀和+哈希表](problems/subarray-sum-equals-k/PrefixSum.cpp) O(n)
- [Copy List with Random Pointer](problems/copy-list-with-random-pointer/README.md) - 随机链表的复制
  - [哈希表映射](problems/copy-list-with-random-pointer/HashMap.cpp) O(n)
- [LRU Cache](problems/lru-cache/README.md) - LRU 缓存
  - [哈希表+双向链表](problems/lru-cache/HashMapAndDoublyLinkedList.cpp) O(1) / 操作

### 双指针

- [Move Zeroes](problems/move-zeroes/README.md) - 移动零
  - [暴力枚举](problems/move-zeroes/BruteForce.cpp) O(n²)
  - [双指针](problems/move-zeroes/TwoPointers.cpp) O(n)
- [Container With Most Water](problems/container-with-most-water/README.md) - 盛最多水的容器
  - [暴力枚举](problems/container-with-most-water/BruteForce.cpp) O(n²)
  - [双指针](problems/container-with-most-water/TwoPointers.cpp) O(n)
- [3Sum](problems/3sum/README.md) - 三数之和
  - [暴力枚举](problems/3sum/BruteForce.cpp) O(n³)
  - [排序+双指针](problems/3sum/TwoPointers.cpp) O(n²)
- [Trapping Rain Water](problems/trapping-rain-water/README.md) - 接雨水
  - [双指针](problems/trapping-rain-water/TwoPointers.cpp) O(n)
  - [动态规划](problems/trapping-rain-water/DynamicProgramming.cpp) O(n)
- [Intersection of Two Linked Lists](problems/intersection-of-two-linked-lists/README.md) - 相交链表
  - [双指针对齐长度](problems/intersection-of-two-linked-lists/TwoPointers.cpp) O(m + n)
- [Reverse Linked List](problems/reverse-linked-list/README.md) - 反转链表
  - [迭代反转](problems/reverse-linked-list/Iterative.cpp) O(n)
- [Merge Two Sorted Lists](problems/merge-two-sorted-lists/README.md) - 合并两个有序链表
  - [哑结点+迭代](problems/merge-two-sorted-lists/Iterative.cpp) O(m + n)
- [Merge k Sorted Lists](problems/merge-k-sorted-lists/README.md) - 合并 K 个升序链表
  - [最小堆（优先队列）](problems/merge-k-sorted-lists/PriorityQueue.cpp) O(N log k)
- [Add Two Numbers](problems/add-two-numbers/README.md) - 两数相加
  - [哑结点+逐位进位](problems/add-two-numbers/Iterative.cpp) O(max(m, n))
- [Remove Nth Node From End of List](problems/remove-nth-node-from-end-of-list/README.md) - 删除链表的倒数第 N 个结点
  - [哑结点+快慢指针](problems/remove-nth-node-from-end-of-list/TwoPointers.cpp) O(L)
- [Swap Nodes in Pairs](problems/swap-nodes-in-pairs/README.md) - 两两交换链表中的节点
  - [哑结点+指针重连](problems/swap-nodes-in-pairs/Iterative.cpp) O(n)
- [Reverse Nodes in k-Group](problems/reverse-nodes-in-k-group/README.md) - K 个一组翻转链表
  - [哑结点+分组反转](problems/reverse-nodes-in-k-group/Iterative.cpp) O(n)
- [Sort List](problems/sort-list/README.md) - 排序链表
  - [归并排序（自顶向下）](problems/sort-list/MergeSort.cpp) O(n log n)
 - [Palindrome Linked List](problems/palindrome-linked-list/README.md) - 回文链表
   - [快慢指针+反转后半段](problems/palindrome-linked-list/TwoPointers.cpp) O(n)
 - [Linked List Cycle](problems/linked-list-cycle/README.md) - 环形链表
   - [快慢指针](problems/linked-list-cycle/Floyd.cpp) O(n)
- [Linked List Cycle II](problems/linked-list-cycle-ii/README.md) - 环形链表 II
  - [Floyd 判圈 + 入环点定位](problems/linked-list-cycle-ii/Floyd.cpp) O(n)

### 二叉树

- [Binary Tree Inorder Traversal](problems/binary-tree-inorder-traversal/README.md) - 二叉树的中序遍历
  - [递归](problems/binary-tree-inorder-traversal/Recursive.cpp) O(n)
  - [迭代+栈](problems/binary-tree-inorder-traversal/Iterative.cpp) O(n)
- [Binary Tree Level Order Traversal](problems/binary-tree-level-order-traversal/README.md) - 二叉树的层序遍历
  - [层序 BFS](problems/binary-tree-level-order-traversal/BFS.cpp) O(n)
- [Maximum Depth of Binary Tree](problems/maximum-depth-of-binary-tree/README.md) - 二叉树的最大深度
  - [递归](problems/maximum-depth-of-binary-tree/Recursive.cpp) O(n)
  - [层序 BFS](problems/maximum-depth-of-binary-tree/BFS.cpp) O(n)
- [Invert Binary Tree](problems/invert-binary-tree/README.md) - 翻转二叉树
  - [递归](problems/invert-binary-tree/Recursive.cpp) O(n)
  - [层序 BFS](problems/invert-binary-tree/BFS.cpp) O(n)
- [Symmetric Tree](problems/symmetric-tree/README.md) - 对称二叉树
  - [递归镜像](problems/symmetric-tree/Recursive.cpp) O(n)
  - [迭代+队列](problems/symmetric-tree/Iterative.cpp) O(n)
- [Diameter of Binary Tree](problems/diameter-of-binary-tree/README.md) - 二叉树的直径
  - [后序 DFS](problems/diameter-of-binary-tree/PostOrderDFS.cpp) O(n)
- [Convert Sorted Array to Binary Search Tree](problems/convert-sorted-array-to-binary-search-tree/README.md) - 将有序数组转换为二叉搜索树
  - [分治（中位数为根）](problems/convert-sorted-array-to-binary-search-tree/DivideAndConquer.cpp) O(n)
- [Construct Binary Tree from Preorder and Inorder Traversal](problems/construct-binary-tree-from-preorder-and-inorder-traversal/README.md) - 从前序与中序遍历序列构造二叉树
  - [递归 + 中序下标哈希](problems/construct-binary-tree-from-preorder-and-inorder-traversal/Recursive.cpp) O(n)
- [Validate Binary Search Tree](problems/validate-binary-search-tree/README.md) - 验证二叉搜索树
  - [递归+上下界](problems/validate-binary-search-tree/RecursiveBounds.cpp) O(n)
  - [中序递增](problems/validate-binary-search-tree/Inorder.cpp) O(n)
- [Kth Smallest Element in a BST](problems/kth-smallest-element-in-a-bst/README.md) - 二叉搜索树中第 K 小的元素
  - [递归中序](problems/kth-smallest-element-in-a-bst/InorderRecursive.cpp) O(h + k)
  - [迭代中序（栈）](problems/kth-smallest-element-in-a-bst/InorderIterative.cpp) O(h + k)
- [Binary Tree Right Side View](problems/binary-tree-right-side-view/README.md) - 二叉树的右视图
  - [层序 BFS](problems/binary-tree-right-side-view/BFS.cpp) O(n)
  - [右优先 DFS](problems/binary-tree-right-side-view/DFS.cpp) O(n)
- [Flatten Binary Tree to Linked List](problems/flatten-binary-tree-to-linked-list/README.md) - 二叉树展开为链表
  - [递归](problems/flatten-binary-tree-to-linked-list/Recursive.cpp) O(n)
  - [迭代 O(1) 额外空间](problems/flatten-binary-tree-to-linked-list/Iterative.cpp) O(n)
- [Path Sum III](problems/path-sum-iii/README.md) - 路径总和 III
  - [DFS + 前缀和 + 哈希表](problems/path-sum-iii/PrefixSum.cpp) O(n)
- [Lowest Common Ancestor of a Binary Tree](problems/lowest-common-ancestor-of-a-binary-tree/README.md) - 二叉树的最近公共祖先
  - [后序递归](problems/lowest-common-ancestor-of-a-binary-tree/Recursive.cpp) O(n)
- [Binary Tree Maximum Path Sum](problems/binary-tree-maximum-path-sum/README.md) - 二叉树中的最大路径和
  - [后序 DFS](problems/binary-tree-maximum-path-sum/PostOrderDFS.cpp) O(n)

### 图

- [Number of Islands](problems/number-of-islands/README.md) - 岛屿数量
  - [DFS 染色](problems/number-of-islands/DFS.cpp) O(m×n)
- [Rotting Oranges](problems/rotting-oranges/README.md) - 腐烂的橘子
  - [多源 BFS](problems/rotting-oranges/BFS.cpp) O(m×n)
- [Course Schedule](problems/course-schedule/README.md) - 课程表
  - [拓扑排序 BFS（Kahn）](problems/course-schedule/TopoSortBFS.cpp) O(V+E)

### 字典树

- [Implement Trie (Prefix Tree)](problems/implement-trie-prefix-tree/README.md) - 实现 Trie（前缀树）
  - [数组子指针](problems/implement-trie-prefix-tree/Trie.cpp) O(|word|) 每次操作

### 滑动窗口

- [Longest Substring Without Repeating Characters](problems/longest-substring-without-repeating-characters/README.md) - 无重复字符的最长子串
  - [暴力枚举](problems/longest-substring-without-repeating-characters/BruteForce.cpp) O(n²)
  - [滑动窗口](problems/longest-substring-without-repeating-characters/SlidingWindow.cpp) O(n)
- [Find All Anagrams in a String](problems/find-all-anagrams-in-a-string/README.md) - 找到字符串中所有字母异位词
  - [滑动窗口](problems/find-all-anagrams-in-a-string/SlidingWindow.cpp) O(n)
- [Sliding Window Maximum](problems/sliding-window-maximum/README.md) - 滑动窗口最大值
  - [暴力枚举](problems/sliding-window-maximum/BruteForce.cpp) O(n * k)
  - [单调队列](problems/sliding-window-maximum/MonotonicQueue.cpp) O(n)
 - [Minimum Window Substring](problems/minimum-window-substring/README.md) - 最小覆盖子串
   - [滑动窗口](problems/minimum-window-substring/SlidingWindow.cpp) O(|s| + |t|)

### 回溯

- [Permutations](problems/permutations/README.md) - 全排列
  - [回溯](problems/permutations/Backtracking.cpp) O(n×n!)
- [Subsets](problems/subsets/README.md) - 子集
  - [回溯](problems/subsets/Backtracking.cpp) O(n×2ⁿ)
- [Letter Combinations of a Phone Number](problems/letter-combinations-of-a-phone-number/README.md) - 电话号码的字母组合
  - [回溯](problems/letter-combinations-of-a-phone-number/Backtracking.cpp) O(4ⁿ×n)
- [Combination Sum](problems/combination-sum/README.md) - 组合总和
  - [回溯+剪枝](problems/combination-sum/Backtracking.cpp) O(n×target/min)
- [Generate Parentheses](problems/generate-parentheses/README.md) - 括号生成
  - [回溯](problems/generate-parentheses/Backtracking.cpp) O(4ⁿ/√n)
- [Palindrome Partitioning](problems/palindrome-partitioning/README.md) - 分割回文串
  - [回溯](problems/palindrome-partitioning/Backtracking.cpp) O(n × 2^n)
- [Word Search](problems/word-search/README.md) - 单词搜索
  - [回溯+DFS](problems/word-search/Backtracking.cpp) O(m×n×3^L)
- [N-Queens](problems/n-queens/README.md) - N 皇后
  - [回溯+列/对角线剪枝](problems/n-queens/Backtracking.cpp) O(n!)

### 二分查找

- [Search Insert Position](problems/search-insert-position/README.md) - 搜索插入位置
  - [二分查找](problems/search-insert-position/BinarySearch.cpp) O(log n)
- [Search a 2D Matrix](problems/search-a-2d-matrix/README.md) - 搜索二维矩阵
  - [二分查找（展平矩阵）](problems/search-a-2d-matrix/BinarySearch.cpp) O(log(m×n))
- [Find First and Last Position of Element in Sorted Array](problems/find-first-and-last-position-of-element-in-sorted-array/README.md) - 在排序数组中查找元素的第一个和最后一个位置
  - [二分查找（两次 lowerBound）](problems/find-first-and-last-position-of-element-in-sorted-array/BinarySearch.cpp) O(log n)
- [Search in Rotated Sorted Array](problems/search-in-rotated-sorted-array/README.md) - 搜索旋转排序数组
  - [二分查找（判断有序半段）](problems/search-in-rotated-sorted-array/BinarySearch.cpp) O(log n)
- [Find Minimum in Rotated Sorted Array](problems/find-minimum-in-rotated-sorted-array/README.md) - 寻找旋转排序数组中的最小值
  - [二分查找（与右边界比较）](problems/find-minimum-in-rotated-sorted-array/BinarySearch.cpp) O(log n)
- [Median of Two Sorted Arrays](problems/median-of-two-sorted-arrays/README.md) - 寻找两个正序数组的中位数
  - [暴力合并排序](problems/median-of-two-sorted-arrays/BruteForce.cpp) O((m+n) log(m+n))
  - [二分查找（切割点）](problems/median-of-two-sorted-arrays/BinarySearch.cpp) O(log(min(m, n)))

### 栈

- [Valid Parentheses](problems/valid-parentheses/README.md) - 有效的括号
  - [栈](problems/valid-parentheses/Stack.cpp) O(n)
- [Min Stack](problems/min-stack/README.md) - 最小栈
  - [辅助最小栈](problems/min-stack/MinStack.cpp) O(1) / 操作
- [Decode String](problems/decode-string/README.md) - 字符串解码
  - [栈](problems/decode-string/Stack.cpp) O(n×k)

### 动态规划

- [Maximum Subarray](problems/maximum-subarray/README.md) - 最大子数组和
  - [暴力枚举](problems/maximum-subarray/BruteForce.cpp) O(n²)
  - [动态规划](problems/maximum-subarray/DynamicProgramming.cpp) O(n)

### 排序

- [Merge Intervals](problems/merge-intervals/README.md) - 合并区间
  - [排序](problems/merge-intervals/Sorting.cpp) O(n log n)

### 数组

- [First Missing Positive](problems/first-missing-positive/README.md) - 缺失的第一个正数
  - [原地哈希](problems/first-missing-positive/InPlaceHash.cpp) O(n)
- [Product of Array Except Self](problems/product-of-array-except-self/README.md) - 除自身以外数组的乘积
  - [前缀积+后缀积](problems/product-of-array-except-self/PrefixProduct.cpp) O(n)
- [Rotate Array](problems/rotate-array/README.md) - 轮转数组
  - [使用额外数组](problems/rotate-array/ExtraArray.cpp) O(n)
  - [三次反转](problems/rotate-array/ThreeReversals.cpp) O(n)
- [Set Matrix Zeroes](problems/set-matrix-zeroes/README.md) - 矩阵置零
  - [原地标记](problems/set-matrix-zeroes/InPlace.cpp) O(m × n)
- [Spiral Matrix](problems/spiral-matrix/README.md) - 螺旋矩阵
  - [模拟法](problems/spiral-matrix/Simulation.cpp) O(m × n)
- [Rotate Image](problems/rotate-image/README.md) - 旋转图像
  - [转置+翻转](problems/rotate-image/TransposeAndReverse.cpp) O(n²)
- [Search a 2D Matrix II](problems/search-a-2d-matrix-ii/README.md) - 搜索二维矩阵 II
  - [从角落搜索](problems/search-a-2d-matrix-ii/SearchFromCorner.cpp) O(m + n)
