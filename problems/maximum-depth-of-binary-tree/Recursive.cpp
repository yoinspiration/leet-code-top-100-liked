#include <algorithm>

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
   * @brief 104. 二叉树的最大深度
   *
   * 深度：从根到最远叶子结点的路径上的结点数。
   * 空树深度为 0。
   */
  int maxDepth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
