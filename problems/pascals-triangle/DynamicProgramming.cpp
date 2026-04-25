#include <vector>
using namespace std;

class Solution
{
public:
  /**
   * @brief 生成杨辉三角的前 numRows 行（动态规划解法）
   *
   * 核心思想：triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
   * - 每行首尾固定为 1
   * - 中间元素由上一行相邻两元素相加得到
   *
   * @param numRows 行数
   * @return vector<vector<int>> 杨辉三角
   */
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> triangle(numRows);

    for (int i = 0; i < numRows; i++)
    {
      triangle[i].resize(i + 1, 1);

      for (int j = 1; j < i; j++)
      {
        triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }
    }

    return triangle;
  }
};
