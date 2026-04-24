class Solution
{
public:
  /**
   * @brief 计算爬到第 n 阶楼梯的不同方案数（动态规划解法）
   *
   * 核心思想：dp[i] 表示爬到第 i 阶的方案数
   * 状态转移：dp[i] = dp[i-1] + dp[i-2]
   * - 到达第 i 阶只有两种情况：从第 i-1 阶爬 1 步，或从第 i-2 阶爬 2 步
   *
   * 空间优化：由于只依赖前两个状态，可以用两个变量代替数组
   *
   * @param n 楼梯总阶数
   * @return int 到达第 n 阶的不同方案数
   */
  int climbStairs(int n)
  {
    if (n <= 2)
    {
      return n;
    }

    int prev2 = 1; // dp[i-2]，对应爬到第 1 阶的方案数
    int prev1 = 2; // dp[i-1]，对应爬到第 2 阶的方案数

    for (int i = 3; i <= n; i++)
    {
      int curr = prev1 + prev2;
      prev2 = prev1;
      prev1 = curr;
    }

    return prev1;
  }
};
