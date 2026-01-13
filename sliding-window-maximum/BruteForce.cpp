class Solution
{
public:
  /**
   * @brief 找到每个滑动窗口中的最大值（暴力枚举解法）
   * 
   * @param nums 输入的整数数组
   * @param k 滑动窗口的大小
   * @return vector<int> 每个滑动窗口的最大值
   */
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    vector<int> result;
    int n = nums.size();

    // 枚举每个滑动窗口
    for (int i = 0; i <= n - k; i++)
    {
      // 找到当前窗口的最大值
      int maxVal = nums[i];
      for (int j = i + 1; j < i + k; j++)
      {
        maxVal = max(maxVal, nums[j]);
      }
      result.push_back(maxVal);
    }

    return result;
  }
};
