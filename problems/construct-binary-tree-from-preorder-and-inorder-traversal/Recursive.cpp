#include <unordered_map>
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
   * @brief 105. 从前序与中序遍历序列构造二叉树
   *
   * 先序首元素为根；在中序中找到根，左侧为左子树中序、右侧为右子树中序；
   * 由左子树结点数确定先序中左子树区间，再递归建树。用哈希表记录中序值到下标，查找根为 O(1)。
   */
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    inIndex_.clear();
    const int n = static_cast<int>(inorder.size());
    for (int i = 0; i < n; ++i)
    {
      inIndex_[inorder[i]] = i;
    }
    return build(preorder, 0, n - 1, inorder, 0, n - 1);
  }

private:
  unordered_map<int, int> inIndex_;

  TreeNode *build(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is,
                  int ie)
  {
    if (ps > pe)
    {
      return nullptr;
    }
    const int rootVal = preorder[ps];
    const int mid = inIndex_[rootVal];
    const int leftSize = mid - is;

    TreeNode *root = new TreeNode(rootVal);
    root->left = build(preorder, ps + 1, ps + leftSize, inorder, is, mid - 1);
    root->right = build(preorder, ps + leftSize + 1, pe, inorder, mid + 1, ie);
    return root;
  }
};
