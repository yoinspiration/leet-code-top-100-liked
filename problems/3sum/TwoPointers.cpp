#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 找到所有不重复的三元组，使得三个数之和为 0
   *
   * @param nums 输入的整数数组
   * @return vector<vector<int>> 所有满足条件的三元组
   */
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> result;
    int n = nums.size();

    // 先对数组进行排序
    sort(nums.begin(), nums.end());

    // 固定第一个数
    for (int i = 0; i < n - 2; i++)
    {
      // 跳过重复的第一个数
      if (i > 0 && nums[i] == nums[i - 1])
      {
        continue;
      }

      // 双指针找剩余两个数
      int left = i + 1;
      int right = n - 1;
      int target = -nums[i]; // 需要找 left + right = target

      while (left < right)
      {
        int sum = nums[left] + nums[right];

        if (sum == target)
        {
          // 找到一组解
          result.push_back({nums[i], nums[left], nums[right]});

          // 跳过重复的 left
          while (left < right && nums[left] == nums[left + 1])
          {
            left++;
          }
          // 跳过重复的 right
          while (left < right && nums[right] == nums[right - 1])
          {
            right--;
          }

          left++;
          right--;
        }
        else if (sum < target)
        {
          // 和太小，left 右移
          left++;
        }
        else
        {
          // 和太大，right 左移
          right--;
        }
      }
    }

    return result;
  }
};
