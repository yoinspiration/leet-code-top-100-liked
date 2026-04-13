#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 46. 全排列
   *
   * 回溯：用 used 数组标记已选元素，每层从所有未选元素中挑一个加入路径，
   * 递归到路径长度等于 nums 长度时记录结果，然后撤销选择（回溯）。
   */
  vector<vector<int>> permute(vector<int> &nums)
  {
    int n = (int)nums.size();
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(n, false);
    backtrack(nums, used, path, result);
    return result;
  }

private:
  void backtrack(const vector<int> &nums, vector<bool> &used,
                 vector<int> &path, vector<vector<int>> &result)
  {
    if ((int)path.size() == (int)nums.size())
    {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < (int)nums.size(); i++)
    {
      if (used[i])
      {
        continue;
      }
      used[i] = true;
      path.push_back(nums[i]);
      backtrack(nums, used, path, result);
      path.pop_back();
      used[i] = false;
    }
  }
};
