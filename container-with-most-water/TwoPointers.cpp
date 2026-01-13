class Solution
{
public:
  /**
   * @brief 找到能够盛最多水的容器
   * 
   * @param height 数组，height[i] 表示第 i 条线的高度
   * @return int 能够盛水的最大面积
   */
  int maxArea(vector<int> &height)
  {
    int left = 0;
    int right = height.size() - 1;
    int result = 0;

    // 双指针从两端向中间移动
    while (left < right)
    {
      // 计算当前容器的面积
      int currentArea = (right - left) * min(height[left], height[right]);
      result = max(result, currentArea);

      // 移动较矮的那一边，因为移动较高的那一边不可能得到更大的面积
      // 容器的面积受限于较矮的边，移动较矮的边才有可能得到更大的面积
      if (height[left] < height[right])
      {
        left++;
      }
      else
      {
        right--;
      }
    }

    return result;
  }
};
