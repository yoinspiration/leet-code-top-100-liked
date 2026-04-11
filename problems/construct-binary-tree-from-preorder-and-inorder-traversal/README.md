# Construct Binary Tree from Preorder and Inorder Traversal

从前序与中序遍历序列构造二叉树

## 题目要求

给定两个整数数组 `preorder` 与 `inorder`，分别表示同一棵二叉树的**先序遍历**与**中序遍历**结果（均无重复元素），构造并返回该二叉树的根结点。

题目链接：[105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)

## 解法：递归 + 中序下标哈希 [Recursive.cpp](Recursive.cpp)

- 先序区间 `[ps, pe]` 的第一个值 `preorder[ps]` 为当前子树的根。
- 在中序区间 `[is, ie]` 中定位根下标 `mid`（用哈希表 `值 -> 下标`，避免每次线性扫描）。
- 左子树中序为 `[is, mid - 1]`，结点数为 `leftSize = mid - is`；对应先序左子树为 `[ps + 1, ps + leftSize]`，先序右子树为 `[ps + leftSize + 1, pe]`；中序右子树为 `[mid + 1, ie]`。
- 递归构建左右子树并接到根上。

- **时间复杂度：O(n)**，每个结点建一次，哈希查找均摊 O(1)。
- **空间复杂度：O(n)**，哈希表 O(n)，递归栈最坏 O(n)。

### 解法说明

若不用哈希表而在中序中线性找根，单次 O(n)，总复杂度会升至 O(n²)。题目保证无重复值，故可用值作为哈希键。
