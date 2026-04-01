#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 54. 螺旋矩阵
   *
   * 给你一个 m 行 n 列的矩阵 matrix，请按照顺时针螺旋顺序，返回矩阵中的所有元素。
   *
   * 核心思想：模拟螺旋遍历
   * - 按照右→下→左→上的顺序遍历
   * - 使用四个边界变量控制遍历范围
   */
  vector<int> spiralOrder(const vector<vector<int>> &matrix)
  {
    const int rows = matrix.size();
    const int cols = matrix[0].size();
    vector<int> result;

    // 定义四个边界
    int top = 0;        // 上边界
    int bottom = rows - 1; // 下边界
    int left = 0;       // 左边界
    int right = cols - 1; // 右边界

    while (top <= bottom && left <= right)
    {
      // 1. 从左到右遍历上边界
      for (int j = left; j <= right; j++)
      {
        result.push_back(matrix[top][j]);
      }
      top++; // 上边界下移

      // 2. 从上到下遍历右边界
      for (int i = top; i <= bottom; i++)
      {
        result.push_back(matrix[i][right]);
      }
      right--; // 右边界左移

      // 3. 从右到左遍历下边界（需要检查是否还有行）
      if (top <= bottom)
      {
        for (int j = right; j >= left; j--)
        {
          result.push_back(matrix[bottom][j]);
        }
        bottom--; // 下边界上移
      }

      // 4. 从下到上遍历左边界（需要检查是否还有列）
      if (left <= right)
      {
        for (int i = bottom; i >= top; i--)
        {
          result.push_back(matrix[i][left]);
        }
        left++; // 左边界右移
      }
    }

    return result;
  }
};
