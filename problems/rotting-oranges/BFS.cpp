#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 994. 腐烂的橘子
   *
   * 多源 BFS：将所有初始腐烂橘子同时入队，按轮次向四周扩散。
   * 每轮处理队列中当前所有结点（即同一分钟内同步腐烂），分钟数 +1。
   * 最终若仍有新鲜橘子则返回 -1，否则返回经过的分钟数。
   */
  int orangesRotting(vector<vector<int>> &grid)
  {
    int m = (int)grid.size();
    int n = (int)grid[0].size();
    int fresh = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 2)
        {
          q.push({i, j});
        }
        else if (grid[i][j] == 1)
        {
          ++fresh;
        }
      }
    }

    if (fresh == 0)
    {
      return 0;
    }

    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minutes = 0;

    while (!q.empty())
    {
      ++minutes;
      int sz = (int)q.size();
      for (int k = 0; k < sz; k++)
      {
        auto [i, j] = q.front();
        q.pop();
        for (auto &d : dirs)
        {
          int ni = i + d[0], nj = j + d[1];
          if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1)
          {
            grid[ni][nj] = 2;
            --fresh;
            q.push({ni, nj});
          }
        }
      }
    }

    return fresh == 0 ? minutes - 1 : -1;
  }
};
