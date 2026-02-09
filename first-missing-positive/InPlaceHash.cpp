#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 41. 缺失的第一个正数
   *
   * 给你一个未排序的整数数组 nums，请你找出其中没有出现的最小的正整数。
   * 要求：时间复杂度 O(n)，空间复杂度 O(1)。
   *
   * 核心思想：原地哈希
   * - 对于长度为 n 的数组，缺失的第一个正数一定在 [1, n+1] 范围内
   * - 如果数组包含 1 到 n 的所有数，那么答案是 n+1
   * - 否则，答案是 [1, n] 中第一个缺失的数
   */
  int firstMissingPositive(vector<int> &nums)
  {
    const int n = nums.size();

    // 第一步：将每个数字 x 放到它应该在的位置（索引 x-1）
    // 例如：数字 1 应该放在索引 0，数字 2 应该放在索引 1，以此类推
    for (int i = 0; i < n; i++)
    {
      // 不断交换，直到：
      // 1. nums[i] 不在 [1, n] 范围内（无法放置）
      // 2. nums[i] 已经在正确的位置（nums[i] == i + 1）
      // 3. 目标位置已经有正确的数字（避免死循环）
      while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
      {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    // 第二步：遍历数组，找到第一个位置 i，使得 nums[i] != i+1
    // 这个位置对应的数字 i+1 就是缺失的第一个正数
    for (int i = 0; i < n; i++)
    {
      if (nums[i] != i + 1)
      {
        return i + 1;
      }
    }

    // 如果数组包含 1 到 n 的所有数，那么缺失的第一个正数是 n+1
    return n + 1;
  }
};
