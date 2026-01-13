class Solution
{
public:
  /**
   * @brief 找到所有和为 k 的连续子数组的个数
   * 
   * @param nums 输入的整数数组
   * @param k 目标和
   * @return int 满足条件的子数组个数
   */
  int subarraySum(vector<int> &nums, int k)
  {
    unordered_map<int, int> prefixSumCount; // 前缀和 -> 出现次数
    prefixSumCount[0] = 1; // 前缀和为 0 出现 1 次（空子数组）
    
    int prefixSum = 0; // 当前前缀和
    int result = 0;

    for (int num : nums)
    {
      prefixSum += num;
      
      // 如果存在前缀和 prefixSum - k，说明存在子数组和为 k
      // 子数组范围：从 prefixSumCount[prefixSum - k] 的位置到当前位置
      if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end())
      {
        result += prefixSumCount[prefixSum - k];
      }
      
      // 更新当前前缀和的计数
      prefixSumCount[prefixSum]++;
    }

    return result;
  }
};
