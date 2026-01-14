#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 找到未排序整数数组中最长连续序列的长度
   *
   * @param nums 输入的整数数组
   * @return int 最长连续序列的长度
   */
  int longestConsecutive(vector<int> &nums)
  {
    if (nums.empty())
    {
      return 0;
    }

    // 将所有数字存入哈希集合，实现 O(1) 查找
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLength = 0;

    for (int num : numSet)
    {
      // 只有当 num-1 不存在时，才从 num 开始计算连续序列
      // 这样可以避免重复计算，每个连续序列只从最小值开始计算一次
      if (numSet.find(num - 1) == numSet.end())
      {
        int currentNum = num;
        int currentLength = 1;

        // 向右扩展，查找连续的数字
        while (numSet.find(currentNum + 1) != numSet.end())
        {
          currentNum++;
          currentLength++;
        }

        maxLength = max(maxLength, currentLength);
      }
    }

    return maxLength;
  }
};
