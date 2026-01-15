#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
   *
   * @param nums 输入的整数数组
   */
  void moveZeroes(vector<int> &nums)
  {
    // 使用双指针：slow 指向下一个非零元素应该放置的位置
    int slow = 0;

    // 第一步：将所有非零元素移动到前面
    for (int fast = 0; fast < nums.size(); fast++)
    {
      if (nums[fast] != 0)
      {
        if (fast != slow)
        {
          nums[slow] = nums[fast];
        }
        slow++;
      }
    }

    // 第二步：将 slow 之后的位置都置为 0
    for (int i = slow; i < nums.size(); i++)
    {
      nums[i] = 0;
    }
  }
};
