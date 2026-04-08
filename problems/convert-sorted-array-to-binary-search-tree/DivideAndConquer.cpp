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
   * @brief 108. 将有序数组转换为二叉搜索树
   *
   * 升序数组的中位数作根，左半区间建左子树、右半区间建右子树，可保证 BST 且高度平衡。
   */
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    return build(nums, 0, static_cast<int>(nums.size()) - 1);
  }

private:
  TreeNode *build(vector<int> &nums, int left, int right)
  {
    if (left > right)
    {
      return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);
    return root;
  }
};
