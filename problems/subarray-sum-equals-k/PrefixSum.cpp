#include <unordered_map>
#include <vector>

using namespace std;

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
  int subarraySum(const vector<int> &nums, int k)
  {
    // 前缀和 -> 出现次数
    // 例如：prefixSumCount[3] = 2 表示前缀和3出现了2次
    unordered_map<int, int> prefixSumCount;
    
    // 初始化：前缀和为0出现1次
    // 为什么？如果 prefixSum == k，说明从数组开头到当前位置的子数组和为k
    // 此时需要 prefixSumCount[0] 来计数
    prefixSumCount[0] = 1;

    int prefixSum = 0; // 当前前缀和（从数组开头到当前位置的所有元素之和）
    int result = 0;    // 结果：和为k的子数组个数

    for (const int num : nums)
    {
      // 更新当前前缀和
      prefixSum += num;

      // 核心思想：如果子数组 [i, j] 的和为 k
      // 那么 prefixSum[j] - prefixSum[i-1] = k
      // 即 prefixSum[i-1] = prefixSum[j] - k
      // 
      // 所以：如果存在前缀和 prefixSum - k，说明存在以当前位置结尾、和为k的子数组
      // 子数组范围：从 prefixSumCount[prefixSum - k] 对应的位置到当前位置
      int target = prefixSum - k;
      if (prefixSumCount.contains(target))
      {
        // 找到了！说明存在多个位置的前缀和都是 target
        // 每个位置都能形成一个和为k的子数组
        result += prefixSumCount[target];
      }

      // 更新当前前缀和的计数（放在检查之后，避免使用当前元素自身）
      prefixSumCount[prefixSum]++;
    }

    return result;
  }
};
