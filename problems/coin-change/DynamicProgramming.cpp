#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
  /**
   * @brief 零钱兑换（动态规划解法）
   *
   * 核心思想：dp[i] 表示凑成金额 i 所需的最少硬币数
   * 状态转移：dp[i] = min(dp[i - coin] + 1)，枚举所有满足 coin <= i 的硬币
   * - 完全背包变体：每种硬币可重复使用，求恰好装满的最少件数
   *
   * @param coins 硬币面额数组
   * @param amount 目标金额
   * @return int 最少硬币数，无法凑成则返回 -1
   */
  int coinChange(vector<int> &coins, int amount)
  {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
      for (int coin : coins)
      {
        if (coin <= i && dp[i - coin] != INT_MAX)
        {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};
