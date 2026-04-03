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
private:
  int diameter_ = 0; // 按边数统计

  // 返回以 node 为根的子树高度（按节点数）
  int height(TreeNode *node)
  {
    if (node == nullptr)
    {
      return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    // 经过当前节点的路径长度（边数）= 左高 + 右高
    diameter_ = max(diameter_, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
  }

public:
  /**
   * @brief 543. 二叉树的直径
   *
   * 直径是任意两个结点之间最长路径的长度（按边数计算），
   * 该路径不一定经过根节点。
   */
  int diameterOfBinaryTree(TreeNode *root)
  {
    diameter_ = 0;
    height(root);
    return diameter_;
  }
};

