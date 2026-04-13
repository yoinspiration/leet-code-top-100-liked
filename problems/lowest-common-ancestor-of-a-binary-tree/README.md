# Lowest Common Ancestor of a Binary Tree

二叉树的最近公共祖先

## 题目要求

给定一棵二叉树的根结点 `root`，以及两个结点 `p` 和 `q`，找出它们的**最近公共祖先**（LCA）。

最近公共祖先的定义：对于有根树中的两个结点 `p`、`q`，LCA 是同时以 `p` 和 `q` 为后代（允许结点为自身后代）的**最深**结点。

题目链接：[236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

## 解法：后序递归 [Recursive.cpp](Recursive.cpp)

后序遍历（先处理左右子树，再处理当前结点）。

**递归终止：**
- `root == nullptr`：未找到，返回 null。
- `root == p` 或 `root == q`：找到目标，返回 root。

**递归处理：**
- 分别在左、右子树中查找 p 和 q，得到 `left`、`right`。
- 若两者均非空，说明 p、q 分居当前结点两侧，当前结点即为 LCA，返回 root。
- 若仅一侧非空，LCA 在那一侧（涵盖 p、q 互为祖先的情况），返回非空侧。

- **时间复杂度：O(n)**，每个结点最多访问一次。
- **空间复杂度：O(h)**，递归栈为树高；最坏（退化链）O(n)，平衡树 O(log n)。
