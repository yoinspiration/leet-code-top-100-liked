# Diameter of Binary Tree

二叉树的直径

## 题目要求

给定一棵二叉树，你需要计算它的直径长度。  
二叉树的直径是任意两个结点路径长度中的最大值，这条路径可能不经过根结点。

注意：本题长度按**边数**计算。

## 解法：后序 DFS + 全局最大值 [PostOrderDFS.cpp](PostOrderDFS.cpp)

### 算法思路

对每个结点 `node`，设：

- `leftHeight`：左子树高度
- `rightHeight`：右子树高度

那么：

- 经过 `node` 的最长路径（按边数）为 `leftHeight + rightHeight`
- 以 `node` 为根的高度为 `1 + max(leftHeight, rightHeight)`

在后序遍历（先算左右，再算当前）中，持续更新全局最大值 `diameter_` 即可。

### 复杂度分析

- **时间复杂度：O(n)**，每个结点访问一次。
- **空间复杂度：O(h)**，递归栈深度为树高 `h`；最坏链状为 `O(n)`。

### 解法评价

这是本题最经典写法：一次 DFS 同时得到高度与直径信息，代码短且高效。

