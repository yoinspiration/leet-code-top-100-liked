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
  bool isMirror(TreeNode *left, TreeNode *right)
  {
    if (left == nullptr && right == nullptr)
    {
      return true;
    }
    if (left == nullptr || right == nullptr)
    {
      return false;
    }
    if (left->val != right->val)
    {
      return false;
    }
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
  }

public:
  /**
   * @brief 101. 对称二叉树
   *
   * 判断二叉树是否轴对称。
   */
  bool isSymmetric(TreeNode *root)
  {
    if (root == nullptr)
    {
      return true;
    }
    return isMirror(root->left, root->right);
  }
};

