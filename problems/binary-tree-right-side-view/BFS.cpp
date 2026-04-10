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
   * @brief 199. 二叉树的右视图（层序 BFS）
   *
   * 按层遍历，每层最后一个结点即该层从右侧看到的结点。
   */
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> result;
    if (root == nullptr)
    {
      return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int levelSize = static_cast<int>(q.size());
      for (int i = 0; i < levelSize; i++)
      {
        TreeNode *node = q.front();
        q.pop();

        if (i == levelSize - 1)
        {
          result.push_back(node->val);
        }
        if (node->left != nullptr)
        {
          q.push(node->left);
        }
        if (node->right != nullptr)
        {
          q.push(node->right);
        }
      }
    }

    return result;
  }
};
