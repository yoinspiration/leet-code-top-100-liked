#include <climits>

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
   * @brief 98. 验证二叉搜索树
   *
   * 有效 BST 的中序遍历为严格递增序列；递归中序时维护前一个值。
   */
  bool isValidBST(TreeNode *root)
  {
    long long prev = LLONG_MIN;
    return inorder(root, prev);
  }

private:
  bool inorder(TreeNode *node, long long &prev)
  {
    if (node == nullptr)
    {
      return true;
    }
    if (!inorder(node->left, prev))
    {
      return false;
    }
    if (node->val <= prev)
    {
      return false;
    }
    prev = node->val;
    return inorder(node->right, prev);
  }
};
