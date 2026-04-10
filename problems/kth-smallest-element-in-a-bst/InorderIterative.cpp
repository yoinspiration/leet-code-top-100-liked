#include <stack>

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
   * @brief 230. 二叉搜索树中第 K 小的元素（迭代中序）
   *
   * 用栈模拟中序遍历，弹出第 k 个结点时即为答案。
   */
  int kthSmallest(TreeNode *root, int k)
  {
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
      --k;
      if (k == 0)
      {
        return cur->val;
      }

      cur = cur->right;
    }

    return -1;
  }
};
