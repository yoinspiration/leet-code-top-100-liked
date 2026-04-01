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
    // 暴力解法：从后往前遍历，遇到 0 就将后面的元素全部前移
    // 从后往前遍历可以避免移动过程中影响未处理的元素
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      if (nums[i] == 0)
      {
        // 将位置 i 之后的所有元素向前移动一位
        for (int j = i; j < nums.size() - 1; j++)
        {
          nums[j] = nums[j + 1];
        }
        // 将最后一个位置置为 0
        nums[nums.size() - 1] = 0;
      }
    }
  }
};
