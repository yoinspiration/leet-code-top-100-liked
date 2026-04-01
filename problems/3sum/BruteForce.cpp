class Solution
{
public:
  /**
   * @brief 找到所有不重复的三元组，使得三个数之和为 0（暴力枚举解法）
   * 
   * @param nums 输入的整数数组
   * @return vector<vector<int>> 所有满足条件的三元组
   */
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> result;
    
    // 使用 set 来去重
    set<vector<int>> uniqueTriplets;
    
    // 三重循环枚举所有可能的三元组
    for (int i = 0; i < nums.size() - 2; i++)
    {
      for (int j = i + 1; j < nums.size() - 1; j++)
      {
        for (int k = j + 1; k < nums.size(); k++)
        {
          if (nums[i] + nums[j] + nums[k] == 0)
          {
            // 将三元组排序后加入 set 去重
            // 注意：即使 i < j < k，但由于原数组未排序，相同数字组合的不同排列
            //（如 [1, -1, 0] 和 [-1, 1, 0]）会被 set 认为是不同的
            // 因此需要排序来统一三元组的表示形式，确保正确去重
            vector<int> triplet = {nums[i], nums[j], nums[k]};
            sort(triplet.begin(), triplet.end());
            uniqueTriplets.insert(triplet);
          }
        }
      }
    }
    
    // 将 set 中的结果复制到 vector 中
    for (const auto &triplet : uniqueTriplets)
    {
      result.push_back(triplet);
    }
    
    return result;
  }
};
