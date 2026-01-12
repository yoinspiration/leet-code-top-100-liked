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
    unordered_map<int, int> map; // 存储元素值到索引的映射

    for (int i = 0; i < nums.size(); i++)
    {
      int complement = target - nums[i];
      
      // 如果 complement 已经在 map 中，说明找到了
      if (map.find(complement) != map.end())
      {
        return {map[complement], i};
      }
      
      // 将当前元素及其索引存入 map
      map[nums[i]] = i;
    }

    return {};
  }
};
