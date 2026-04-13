#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 207. 课程表
   *
   * 拓扑排序（Kahn 算法）：若有向图存在拓扑序，则无环，课程可全部完成。
   * 统计每个结点的入度，将入度为 0 的结点入队，每次出队时将其邻居入度 -1，
   * 若邻居入度变为 0 则入队。最终处理的结点数等于 numCourses 则无环。
   */
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto &pre : prerequisites)
    {
      adj[pre[1]].push_back(pre[0]);
      ++indegree[pre[0]];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    int finished = 0;
    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      ++finished;
      for (int next : adj[cur])
      {
        if (--indegree[next] == 0)
        {
          q.push(next);
        }
      }
    }

    return finished == numCourses;
  }
};
