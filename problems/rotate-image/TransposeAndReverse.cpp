#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 48. 旋转图像
   *
   * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
   * 要求：必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
   *
   * 核心思想：转置 + 翻转
   * - 先转置矩阵（沿主对角线翻转）
   * - 再每一行左右翻转
   * - 组合效果 = 顺时针旋转 90°
   */
  void rotate(vector<vector<int>> &matrix)
  {
    const int n = matrix.size();

    // 第一步：转置矩阵（沿主对角线翻转）
    // matrix[i][j] 和 matrix[j][i] 交换（只遍历上三角，避免重复交换）
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // 第二步：每一行左右翻转
    for (int i = 0; i < n; i++)
    {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};
