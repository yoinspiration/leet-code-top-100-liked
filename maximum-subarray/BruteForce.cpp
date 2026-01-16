#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 找到最大子数组和（暴力枚举解法）
   *
   * @param nums 输入的整数数组
   * @return int 最大子数组和
   */
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    int maxSum = nums[0]; // 初始化为第一个元素

    // 双重循环枚举所有可能的子数组
    for (int i = 0; i < n; i++)
    {
      int sum = 0; // 从位置 i 开始的子数组和
      for (int j = i; j < n; j++)
      {
        sum += nums[j];            // 累加子数组 [i, j] 的和
        maxSum = max(maxSum, sum); // 更新最大和
      }
    }

    return maxSum;
  }
};
