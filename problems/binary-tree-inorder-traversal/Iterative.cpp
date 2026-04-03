#include <stack>
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
   * @brief 94. 二叉树的中序遍历（迭代）
   *
   * 用栈模拟递归：沿左子树一路入栈，弹出时访问结点，再转向右子树。
   */
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> result;
    stack<TreeNode *> st;
    TreeNode *cur = root;

    while (cur != nullptr || !st.empty())
    {
      while (cur != nullptr)
      {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      result.push_back(cur->val);
      cur = cur->right;
    }

    return result;
  }
};
