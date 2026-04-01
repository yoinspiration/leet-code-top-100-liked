#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 73. 矩阵置零
   *
   * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。
   * 要求：O(1) 空间复杂度（原地操作）。
   *
   * 核心思想：使用第一行和第一列作为标记
   * - 用第一行标记哪些列需要置零
   * - 用第一列标记哪些行需要置零
   * - 需要额外记录第一行和第一列本身是否需要置零
   */
  void setZeroes(vector<vector<int>> &matrix)
  {
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    // 记录第一行和第一列是否需要置零
    bool firstRowZero = false;
    bool firstColZero = false;

    // 检查第一行是否有 0
    for (int j = 0; j < cols; j++)
    {
      if (matrix[0][j] == 0)
      {
        firstRowZero = true;
        break;
      }
    }

    // 检查第一列是否有 0
    for (int i = 0; i < rows; i++)
    {
      if (matrix[i][0] == 0)
      {
        firstColZero = true;
        break;
      }
    }

    // 使用第一行和第一列作为标记
    // 如果 matrix[i][j] == 0，则标记 matrix[i][0] = 0 和 matrix[0][j] = 0
    for (int i = 1; i < rows; i++)
    {
      for (int j = 1; j < cols; j++)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][0] = 0; // 标记第 i 行需要置零
          matrix[0][j] = 0; // 标记第 j 列需要置零
        }
      }
    }

    // 根据标记，将对应的行和列置零
    for (int i = 1; i < rows; i++)
    {
      for (int j = 1; j < cols; j++)
      {
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
        {
          matrix[i][j] = 0;
        }
      }
    }

    // 处理第一行
    if (firstRowZero)
    {
      for (int j = 0; j < cols; j++)
      {
        matrix[0][j] = 0;
      }
    }

    // 处理第一列
    if (firstColZero)
    {
      for (int i = 0; i < rows; i++)
      {
        matrix[i][0] = 0;
      }
    }
  }
};
