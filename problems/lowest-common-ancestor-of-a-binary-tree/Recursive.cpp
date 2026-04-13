using namespace std;

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
public:
  /**
   * @brief 236. 二叉树的最近公共祖先
   *
   * 后序遍历：先在左右子树中查找 p 和 q。
   * - 若左右子树各返回一个非空结果，说明 p、q 分布两侧，当前结点即为 LCA。
   * - 若仅一侧非空，则该侧的返回值就是 LCA（p/q 互为祖先，或两者都在同侧）。
   */
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == nullptr || root == p || root == q)
    {
      return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr)
    {
      return root;
    }
    return left != nullptr ? left : right;
  }
};
