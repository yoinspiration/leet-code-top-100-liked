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
   * @brief 101. 对称二叉树（迭代）
   *
   * 用队列成对比较镜像位置结点。
   */
  bool isSymmetric(TreeNode *root)
  {
    if (root == nullptr)
    {
      return true;
    }

    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty())
    {
      TreeNode *left = q.front();
      q.pop();
      TreeNode *right = q.front();
      q.pop();

      if (left == nullptr && right == nullptr)
      {
        continue;
      }
      if (left == nullptr || right == nullptr)
      {
        return false;
      }
      if (left->val != right->val)
      {
        return false;
      }

      q.push(left->left);
      q.push(right->right);
      q.push(left->right);
      q.push(right->left);
    }

    return true;
  }
};

