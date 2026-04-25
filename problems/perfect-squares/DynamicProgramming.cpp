#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
  /**
   * @brief 完全平方数（动态规划解法）
   *
   * 核心思想：dp[i] 表示和为 i 所需的最少完全平方数个数
   * 状态转移：dp[i] = min(dp[i - j*j] + 1)，枚举所有满足 j*j <= i 的 j
   * - 完全背包变体：每个完全平方数可重复使用
   *
   * @param n 目标整数
   * @return int 最少完全平方数个数
   */
  int numSquares(int n)
  {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j * j <= i; j++)
      {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }

    return dp[n];
  }
};
