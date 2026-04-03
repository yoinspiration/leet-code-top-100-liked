# Symmetric Tree

对称二叉树

## 题目要求

给你一个二叉树的根节点 `root`，检查它是否轴对称。

## 解法一：递归镜像判断 [Recursive.cpp](Recursive.cpp)

定义函数 `isMirror(left, right)` 判断两棵子树是否互为镜像：

- 都为空：是镜像
- 仅一边为空：不是镜像
- 值不同：不是镜像
- 否则继续比较：
  - `left->left` 与 `right->right`
  - `left->right` 与 `right->left`

- **时间复杂度：O(n)**，每个结点最多比较一次。
- **空间复杂度：O(h)**，递归栈深度为树高。

## 解法二：迭代 + 队列 [Iterative.cpp](Iterative.cpp)

把需要镜像比较的结点成对入队，每次出队两项比较：

- 若都为空，继续
- 若仅一边为空或值不同，返回 `false`
- 否则按镜像顺序入队：
  - `left->left` 与 `right->right`
  - `left->right` 与 `right->left`

队列处理结束仍未失败，则为对称树。

- **时间复杂度：O(n)**
- **空间复杂度：O(w)**，`w` 为某一层最大宽度。

### 解法评价

递归表达力更强；迭代更接近显式状态机，两种都属于面试高频写法。

