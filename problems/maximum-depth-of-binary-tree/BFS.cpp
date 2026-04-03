#include <queue>

using namespace std;

// LeetCode 会提供 TreeNode 的定义，这里仅作注释说明：
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution
{
public:
  /**
   * @brief 104. 二叉树的最大深度（层序遍历）
   *
   * 按层扩展队列，层数即为最大深度。
   */
  int maxDepth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }

    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;

    while (!q.empty())
    {
      int levelSize = static_cast<int>(q.size());
      depth++;
      for (int i = 0; i < levelSize; i++)
      {
        TreeNode *node = q.front();
        q.pop();
        if (node->left != nullptr)
        {
          q.push(node->left);
        }
        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }
    }

    return depth;
  }
};
