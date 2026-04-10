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
   * @brief 230. 二叉搜索树中第 K 小的元素（递归中序）
   *
   * BST 的中序遍历是升序序列，遍历到第 k 个结点即可返回。
   */
  int kthSmallest(TreeNode *root, int k)
  {
    int answer = 0;
    inorder(root, k, answer);
    return answer;
  }

private:
  void inorder(TreeNode *node, int &k, int &answer)
  {
    if (node == nullptr || k == 0)
    {
      return;
    }

    inorder(node->left, k, answer);
    if (k == 0)
    {
      return;
    }

    --k;
    if (k == 0)
    {
      answer = node->val;
      return;
    }

    inorder(node->right, k, answer);
  }
};
