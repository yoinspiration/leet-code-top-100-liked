class Solution
{
public:
  /**
   * @brief 找到数组中两数之和等于目标值的索引
   * 
   * @param nums 输入的整数数组
   * @param target 目标值
   * @return vector<int> 包含两个索引的向量，如果未找到则返回空向量
   */
  vector<int> twoSum(vector<int> &nums, int target)
  {
    // 对于 vector<int>，size() 是 O(1) 操作
    for (int i = 0; i < nums.size() - 1; i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        if (nums[i] + nums[j] == target)
        {
          return {i, j};
        }
      }
    }

    return {};
  }
};
