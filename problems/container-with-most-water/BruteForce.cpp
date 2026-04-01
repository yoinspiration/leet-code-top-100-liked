class Solution
{
public:
  /**
   * @brief 找到能够盛最多水的容器（暴力枚举解法）
   * 
   * @param height 数组，height[i] 表示第 i 条线的高度
   * @return int 能够盛水的最大面积
   */
  int maxArea(vector<int> &height)
  {
    int result = 0;
    
    // 双重循环枚举所有可能的容器组合
    for (int i = 0; i < height.size() - 1; i++)
    {
      for (int j = i + 1; j < height.size(); j++)
      {
        // 容器的高度取两条线中较矮的那条
        int lower = height[i] < height[j] ? height[i] : height[j];
        // 容器的宽度是两条线之间的距离
        int area = (j - i) * lower;
        
        // 更新最大面积
        if (area > result)
        {
          result = area;
        }
      }
    }
    
    return result;
  }
};
