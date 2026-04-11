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
   * @brief 114. 二叉树展开为链表（迭代，O(1) 额外空间）
   *
   * 对当前结点：若有左子树，找到左子树最右结点，把原右子树挂在其右指针上，
   * 再把整棵左子树移到右指针，清空左指针；然后沿右指针前进。
   * 等价于按先序把「下一个」结点逐步接到右侧。
   */
  void flatten(TreeNode *root)
  {
    TreeNode *curr = root;
    while (curr != nullptr)
    {
      if (curr->left != nullptr)
      {
        TreeNode *pre = curr->left;
        while (pre->right != nullptr)
        {
          pre = pre->right;
        }
        pre->right = curr->right;
        curr->right = curr->left;
        curr->left = nullptr;
      }
      curr = curr->right;
    }
  }
};
