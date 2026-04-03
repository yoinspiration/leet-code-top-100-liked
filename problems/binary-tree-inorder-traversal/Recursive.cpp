#include <vector>

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
private:
  void inorder(TreeNode *node, vector<int> &out)
  {
    if (node == nullptr)
    {
      return;
    }
    inorder(node->left, out);
    out.push_back(node->val);
    inorder(node->right, out);
  }

public:
  /**
   * @brief 94. 二叉树的中序遍历
   *
   * 左子树 -> 根 -> 右子树
   */
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> result;
    inorder(root, result);
    return result;
  }
};
