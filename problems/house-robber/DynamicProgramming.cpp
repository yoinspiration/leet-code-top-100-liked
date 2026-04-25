#include <vector>
using namespace std;

class Solution
{
public:
  /**
   * @brief 打家劫舍（动态规划解法）
   *
   * 核心思想：dp[i] 表示前 i 间房屋能偷到的最高金额
   * 状态转移：dp[i] = max(dp[i-1], dp[i-2] + nums[i])
   * - 不偷第 i 间：沿用 dp[i-1]
   * - 偷第 i 间：不能偷第 i-1 间，取 dp[i-2] + nums[i]
   *
   * 空间优化：只依赖前两个状态，用两个变量滚动更新
   *
   * @param nums 每间房屋的金额
   * @return int 能偷到的最高金额
   */
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
      int curr = max(prev1, prev2 + nums[i]);
      prev2 = prev1;
      prev1 = curr;
    }

    return prev1;
  }
};
