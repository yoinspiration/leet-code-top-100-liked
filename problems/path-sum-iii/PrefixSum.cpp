#include <unordered_map>

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
   * @brief 437. 路径总和 III
   *
   * 统计路径和为 targetSum 的路径条数；路径须沿父到子，起点与终点任意（不必根或叶）。
   * DFS 遍历时维护根到当前结点的前缀和，哈希表记录各前缀和在「当前根到叶这条竖链」上的出现次数；
   * 若存在前缀和 curr - targetSum，则有一段竖直子路径和为 targetSum。离开子树时回溯哈希计数。
   */
  int pathSum(TreeNode *root, int targetSum)
  {
    target_ = static_cast<long long>(targetSum);
    count_ = 0;
    prefix_.clear();
    prefix_[0] = 1;
    dfs(root, 0);
    return static_cast<int>(count_);
  }

private:
  long long target_{};
  long long count_{};
  unordered_map<long long, int> prefix_;

  void dfs(TreeNode *node, long long curr)
  {
    if (node == nullptr)
    {
      return;
    }
    curr += static_cast<long long>(node->val);

    const auto it = prefix_.find(curr - target_);
    if (it != prefix_.end())
    {
      count_ += it->second;
    }
    prefix_[curr]++;

    dfs(node->left, curr);
    dfs(node->right, curr);

    prefix_[curr]--;
    if (prefix_[curr] == 0)
    {
      prefix_.erase(curr);
    }
  }
};
