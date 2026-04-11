# Flatten Binary Tree to Linked List

二叉树展开为链表

## 题目要求

给定二叉树根结点 `root`，将其**原地**展开为一条「链表」：展开顺序为二叉树的**先序遍历**；展开后结点无左孩子，右指针指向下一个结点。链表头仍为原树的根。

题目链接：[114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/)

## 解法一：递归 [Recursive.cpp](Recursive.cpp)

先递归展平左、右子树；再将原左子树接到 `root->right`，原右子树接到「展平后左子链」的末尾（从左子树根一直往右走到尾），并清空 `root->left`。

- **时间复杂度：O(n)**，每个结点被访问常数次。
- **空间复杂度：O(h)**，递归栈深度为树高，最坏 `O(n)`。

## 解法二：迭代（O(1) 额外空间）[Iterative.cpp](Iterative.cpp)

从左向右处理：若当前结点有左子树，在左子树中沿 `right` 走到最右结点 `pre`，令 `pre->right` 指向当前结点的原右子树，再把整棵左子树移到 `root->right`，`root->left` 置空；然后 `curr = curr->right` 继续。等价于按先序逐步把「下一个」结点接到右侧。

- **时间复杂度：O(n)**。
- **空间复杂度：O(1)**，仅若干指针。

### 解法评价

递归思路清晰，与「先序 + 拼接」一致；迭代版适合强调原地、常数额外空间。两者线性时间，按需选用。
