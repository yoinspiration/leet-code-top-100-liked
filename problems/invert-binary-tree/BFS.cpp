#include <queue>
#include <utility>

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
   * @brief 226. 翻转二叉树（层序遍历）
   *
   * 对每个访问到的结点交换左右孩子，再将非空孩子入队。
   */
  TreeNode *invertTree(TreeNode *root)
  {
    if (root == nullptr)
    {
      return nullptr;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      swap(node->left, node->right);
      if (node->left != nullptr)
      {
        q.push(node->left);
      }
      if (node->right != nullptr)
      {
        q.push(node->right);
      }
    }

    return root;
  }
};
