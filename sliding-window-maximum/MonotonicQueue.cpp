class Solution
{
public:
  /**
   * @brief 找到每个滑动窗口中的最大值
   * 
   * @param nums 输入的整数数组
   * @param k 滑动窗口的大小
   * @return vector<int> 每个滑动窗口的最大值
   */
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    vector<int> result;
    deque<int> dq; // 双端队列，存储索引，保证队列中的元素按值从大到小排列

    for (int i = 0; i < nums.size(); i++)
    {
      // 移除窗口外的元素（队列中存储的是索引）
      while (!dq.empty() && dq.front() <= i - k)
      {
        dq.pop_front();
      }

      // 移除队列中所有小于当前元素的元素（因为它们在当前窗口内不可能是最大值）
      while (!dq.empty() && nums[dq.back()] < nums[i])
      {
        dq.pop_back();
      }

      // 将当前元素的索引加入队列
      dq.push_back(i);

      // 当窗口大小达到 k 时，记录最大值
      if (i >= k - 1)
      {
        result.push_back(nums[dq.front()]);
      }
    }

    return result;
  }
};
