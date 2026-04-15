#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 78. 子集
   *
   * 回溯：每次从 start 位置开始枚举，选一个元素加入路径后递归，
   * 递归返回后撤销（pop_back）。每进入递归就记录当前路径（含空集）。
   */
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(nums, 0, path, result);
    return result;
  }

private:
  void backtrack(const vector<int> &nums, int start,
                 vector<int> &path, vector<vector<int>> &result)
  {
    result.push_back(path); // 每个路径都是一个合法子集

    for (int i = start; i < (int)nums.size(); i++)
    {
      path.push_back(nums[i]); // 选择 nums[i]
      backtrack(nums, i + 1, path, result);
      path.pop_back(); // 撤销选择
    }
  }
};
