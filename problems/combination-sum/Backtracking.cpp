#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 39. 组合总和
   *
   * 回溯：先排序以便剪枝，每次从 start 开始枚举，同一元素可重复选
   * （递归时传 i 而非 i+1），当 remain == 0 时记录结果。
   * 若当前元素已大于剩余值则后续更大的元素也无需尝试（剪枝）。
   */
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> path;
    backtrack(candidates, 0, target, path, result);
    return result;
  }

private:
  void backtrack(const vector<int> &candidates, int start, int remain,
                 vector<int> &path, vector<vector<int>> &result)
  {
    if (remain == 0)
    {
      result.push_back(path);
      return;
    }
    for (int i = start; i < (int)candidates.size(); i++)
    {
      if (candidates[i] > remain) // 剪枝：后续元素更大，不必继续
      {
        break;
      }
      path.push_back(candidates[i]);
      backtrack(candidates, i, remain - candidates[i], path, result); // i 不加1，允许重复选
      path.pop_back();
    }
  }
};
