class Solution
{
public:
  /**
   * @brief 计算能够接到的雨水总量
   * 
   * @param height 数组，height[i] 表示第 i 个位置的高度
   * @return int 能够接到的雨水总量
   */
  int trap(vector<int> &height)
  {
    if (height.empty())
    {
      return 0;
    }

    int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;  // 左边遇到的最大高度
    int rightMax = 0; // 右边遇到的最大高度
    int result = 0;

    while (left < right)
    {
      if (height[left] < height[right])
      {
        // 处理左边
        if (height[left] >= leftMax)
        {
          leftMax = height[left];
        }
        else
        {
          // 当前位置能够接到的雨水 = leftMax - height[left]
          result += leftMax - height[left];
        }
        left++;
      }
      else
      {
        // 处理右边
        if (height[right] >= rightMax)
        {
          rightMax = height[right];
        }
        else
        {
          // 当前位置能够接到的雨水 = rightMax - height[right]
          result += rightMax - height[right];
        }
        right--;
      }
    }

    return result;
  }
};
