# Kth Smallest Element in a BST

二叉搜索树中第 K 小的元素

## 题目要求

给定一个二叉搜索树的根结点 `root`，和一个整数 `k`，请找出其中第 `k` 小的元素值（从 `1` 开始计数）。

题目链接：[230. 二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/)

## 解法一：递归中序 [InorderRecursive.cpp](InorderRecursive.cpp)

BST 的中序遍历结果是升序序列，因此遍历到第 `k` 个访问的结点时即得到答案。实现时用引用传递 `k`，每访问一个结点就 `--k`，当 `k == 0` 记录答案并提前停止递归。

- **时间复杂度：O(h + k)**，在最坏情况下为 `O(n)`。
- **空间复杂度：O(h)**，递归栈深度为树高。

## 解法二：迭代中序（栈）[InorderIterative.cpp](InorderIterative.cpp)

用栈模拟中序遍历流程：不断向左压栈，弹栈访问时计数，弹出第 `k` 个结点即返回。

- **时间复杂度：O(h + k)**，最坏 `O(n)`。
- **空间复杂度：O(h)**，显式栈深度为树高。

### 解法评价

两种做法本质一致，都是利用 BST 的中序有序性。递归代码简洁；迭代可避免深递归栈风险。
