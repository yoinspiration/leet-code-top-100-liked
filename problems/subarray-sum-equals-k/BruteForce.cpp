class Solution
{
public:
  /**
   * @brief 找到所有和为 k 的连续子数组的个数（暴力枚举解法）
   * 
   * @param nums 输入的整数数组
   * @param k 目标和
   * @return int 满足条件的子数组个数
   */
  int subarraySum(vector<int> &nums, int k)
  {
    int result = 0;
    int n = nums.size();

    // 双重循环枚举所有可能的子数组
    for (int i = 0; i < n; i++)
    {
      int sum = 0; // 每次新的起点 i，sum 都会重新初始化为 0
      for (int j = i; j < n; j++)
      {
        sum += nums[j];
        if (sum == k)
        {
          result++;
        }
      }
    }

    return result;
  }
};
