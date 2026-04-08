# Convert Sorted Array to Binary Search Tree

将有序数组转换为二叉搜索树

## 题目要求

给你一个整数数组 `nums`，其中元素已经按**升序**排列，请你将其转换为一棵**高度平衡**的二叉搜索树。

高度平衡二叉树是指：二叉树每个节点的左右两个子树的高度差的绝对值不超过 1。

题目链接：[108. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

## 解法：分治（选中位数为根）[DivideAndConquer.cpp](DivideAndConquer.cpp)

对当前区间 `[left, right]`：

- 若 `left > right`，返回空；
- 否则取中点 `mid = left + (right - left) / 2`（避免 `(left + right)` 溢出），`nums[mid]` 作为根；
- 递归构建左子树 `[left, mid - 1]`、右子树 `[mid + 1, right]`。

升序数组的中位数在 BST 中序遍历序列里处于「中间」位置，这样左右子树规模至多相差 1，树高平衡；同时左子树值均小于根、右子树值均大于根，满足 BST。

- **时间复杂度：O(n)**，每个下标作为根各建一次。
- **空间复杂度：O(h)**，递归栈为树高，平衡时 `O(log n)`；最坏退化为链时 `O(n)`。
