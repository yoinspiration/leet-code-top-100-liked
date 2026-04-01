#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 240. 搜索二维矩阵 II
   *
   * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。
   * 该矩阵具有以下特性：
   * - 每行的元素从左到右升序排列
   * - 每列的元素从上到下升序排列
   *
   * 核心思想：从右上角（或左下角）开始搜索
   * - 从右上角开始：如果当前值 > target，向左移动；如果当前值 < target，向下移动
   * - 利用矩阵的有序性，每次排除一行或一列
   */
  bool searchMatrix(const vector<vector<int>> &matrix, int target)
  {
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    // 从右上角开始搜索
    int i = 0;        // 当前行（从上到下）
    int j = cols - 1; // 当前列（从右到左）

    while (i < rows && j >= 0)
    {
      const int current = matrix[i][j];

      if (current == target)
      {
        return true;
      }
      else if (current > target)
      {
        // 当前值大于目标值，向左移动（排除当前列）
        j--;
      }
      else
      {
        // 当前值小于目标值，向下移动（排除当前行）
        i++;
      }
    }

    return false;
  }
};
