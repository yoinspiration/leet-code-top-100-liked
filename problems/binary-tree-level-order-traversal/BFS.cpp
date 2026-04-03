#include <queue>
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
   * @brief 102. 二叉树的层序遍历（BFS）
   *
   * 使用队列按层遍历，每次处理当前层固定数量的结点。
   */
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    if (root == nullptr)
    {
      return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int levelSize = static_cast<int>(q.size());
      vector<int> level;
      level.reserve(levelSize);

      for (int i = 0; i < levelSize; i++)
      {
        TreeNode *node = q.front();
        q.pop();
        level.push_back(node->val);

        if (node->left != nullptr)
        {
          q.push(node->left);
        }
        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }

      result.push_back(level);
    }

    return result;
  }
};
