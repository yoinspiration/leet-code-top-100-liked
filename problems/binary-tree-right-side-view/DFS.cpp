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
public:
  /**
   * @brief 199. 二叉树的右视图（DFS）
   *
   * 先访问右子树，再访问左子树；每层第一次到达的结点就是该层右视图。
   */
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> result;
    dfs(root, 0, result);
    return result;
  }

private:
  void dfs(TreeNode *node, int depth, vector<int> &result)
  {
    if (node == nullptr)
    {
      return;
    }
    if (depth == static_cast<int>(result.size()))
    {
      result.push_back(node->val);
    }
    dfs(node->right, depth + 1, result);
    dfs(node->left, depth + 1, result);
  }
};
