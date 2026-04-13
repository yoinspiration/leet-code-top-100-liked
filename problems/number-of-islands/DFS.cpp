#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 200. 岛屿数量
   *
   * 遍历网格，遇到 '1' 则岛屿数 +1，并用 DFS 将该岛屿所有相连的 '1' 标记为 '0'，
   * 避免重复计数。原地修改，无需额外 visited 数组。
   */
  int numIslands(vector<vector<char>> &grid)
  {
    m_ = (int)grid.size();
    n_ = (int)grid[0].size();
    int count = 0;
    for (int i = 0; i < m_; i++)
    {
      for (int j = 0; j < n_; j++)
      {
        if (grid[i][j] == '1')
        {
          ++count;
          dfs(grid, i, j);
        }
      }
    }
    return count;
  }

private:
  int m_, n_;

  void dfs(vector<vector<char>> &grid, int i, int j)
  {
    if (i < 0 || i >= m_ || j < 0 || j >= n_ || grid[i][j] != '1')
    {
      return;
    }
    grid[i][j] = '0'; // 标记为已访问
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  }
};
