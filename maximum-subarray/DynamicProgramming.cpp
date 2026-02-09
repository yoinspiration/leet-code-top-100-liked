#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 找到最大子数组和（动态规划/Kadane算法）
   *
   * 核心思想：dp[i] 表示以位置 i 结尾的最大子数组和
   * 状态转移：dp[i] = max(nums[i], dp[i-1] + nums[i])
   * - 如果 dp[i-1] > 0，则继续累加
   * - 如果 dp[i-1] <= 0，则重新开始（只取 nums[i]）
   *
   * 空间优化：由于只依赖前一个状态，可以用一个变量代替数组
   *
   * @param nums 输入的整数数组
   * @return int 最大子数组和
   */
  int maxSubArray(const vector<int> &nums)
  {
    const int n = nums.size();
    int maxSum = nums[0];     // 全局最大和，记录所有位置中最大的 currentSum
    int currentSum = nums[0]; // 以当前位置结尾的最大子数组和

    for (int i = 1; i < n; i++)
    {
      // 核心状态转移：currentSum = max(nums[i], currentSum + nums[i])
      //
      // 为什么这样转移？
      // 以位置 i 结尾的最大子数组和，只有两种可能：
      // 1. 只包含 nums[i] 自己（重新开始）
      // 2. 包含前面的子数组 + nums[i]（继续累加）
      //
      // 如果 currentSum > 0：
      //   - 继续累加：currentSum + nums[i] 可能更大
      //   - 例如：currentSum=5, nums[i]=3 → 累加得到8，比只取3更好
      //
      // 如果 currentSum <= 0：
      //   - 继续累加：currentSum + nums[i] <= nums[i]（因为 currentSum <= 0）
      //   - 重新开始：只取 nums[i] 会更好
      //   - 例如：currentSum=-2, nums[i]=4 → 累加得到2，不如只取4
      currentSum = max(nums[i], currentSum + nums[i]);

      // 更新全局最大和
      // 因为最大子数组可能以任意位置结尾，所以需要记录所有 currentSum 中的最大值
      maxSum = max(maxSum, currentSum);
    }

    return maxSum;
  }
};
