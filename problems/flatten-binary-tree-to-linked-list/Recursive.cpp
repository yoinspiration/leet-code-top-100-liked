#include <cstddef>

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
   * @brief 114. 二叉树展开为链表（递归）
   *
   * 先递归展平左右子树，再把左链接到根的右指针，原右子树接到左子树最右结点之后。
   * 展开顺序为先序，结果用右指针串成单链表。
   */
  void flatten(TreeNode *root)
  {
    if (root == nullptr)
    {
      return;
    }
    flatten(root->left);
    flatten(root->right);

    TreeNode *left = root->left;
    TreeNode *right = root->right;
    root->left = nullptr;
    root->right = left;

    TreeNode *tail = root;
    while (tail->right != nullptr)
    {
      tail = tail->right;
    }
    tail->right = right;
  }
};
