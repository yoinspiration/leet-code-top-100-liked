class Solution
{
public:
  /**
   * @brief 计算能够接到的雨水总量（动态规划解法）
   * 
   * @param height 数组，height[i] 表示第 i 个位置的高度
   * @return int 能够接到的雨水总量
   */
  int trap(vector<int> &height)
  {
    int n = height.size();
    if (n == 0)
    {
      return 0;
    }

    // leftMax[i] 表示位置 i 左边（包括 i）的最大高度
    vector<int> leftMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
      leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // rightMax[i] 表示位置 i 右边（包括 i）的最大高度
    vector<int> rightMax(n);
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
      rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // 计算每个位置能够接到的雨水
    int result = 0;
    for (int i = 0; i < n; i++)
    {
      // 当前位置能够接到的雨水 = min(leftMax[i], rightMax[i]) - height[i]
      result += min(leftMax[i], rightMax[i]) - height[i];
    }

    return result;
  }
};
