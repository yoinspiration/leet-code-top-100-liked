using namespace std;

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
public:
  /**
   * @brief 124. 二叉树中的最大路径和
   *
   * 后序 DFS：对每个结点计算「以该结点为根的最大贡献值」（向上延伸的单侧最长路径）。
   * 在计算过程中，用左贡献 + 当前值 + 右贡献 更新全局答案（该结点为路径最高点）。
   * 贡献值取 max(0, 子树贡献)，负贡献直接舍弃。
   */
  int maxPathSum(TreeNode *root)
  {
    int ans = INT_MIN;
    gain(root, ans);
    return ans;
  }

private:
  // 返回以 node 为端点、向下延伸的最大路径和（单侧贡献）
  int gain(TreeNode *node, int &ans)
  {
    if (node == nullptr)
    {
      return 0;
    }

    int left = max(0, gain(node->left, ans));
    int right = max(0, gain(node->right, ans));

    // 以当前结点为最高点的路径和
    ans = max(ans, node->val + left + right);

    // 向父结点只能选一侧
    return node->val + max(left, right);
  }
};
