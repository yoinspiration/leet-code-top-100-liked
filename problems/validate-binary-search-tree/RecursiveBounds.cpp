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
   * 每个结点值须落在 (low, high) 开区间内；左子树收紧上界为当前值，右子树收紧下界为当前值。
   * 上下界用 long long，避免与 INT_MIN/INT_MAX 比较时溢出。
   */
  bool isValidBST(TreeNode *root)
  {
    return validate(root, LLONG_MIN, LLONG_MAX);
  }

private:
  bool validate(TreeNode *node, long long low, long long high)
  {
    if (node == nullptr)
    {
      return true;
    }
    if (node->val <= low || node->val >= high)
    {
      return false;
    }
    return validate(node->left, low, node->val) &&
           validate(node->right, node->val, high);
  }
};
