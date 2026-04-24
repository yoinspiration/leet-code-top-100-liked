#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int jump(const vector<int> &nums)
  {
    int jumps = 0;
    int curEnd = 0;   // 当前跳跃能覆盖的最远边界
    int maxReach = 0; // 全局最远可达下标

    for (int i = 0; i < (int)nums.size() - 1; i++)
    {
      maxReach = max(maxReach, i + nums[i]);
      if (i == curEnd)
      {
        jumps++;
        curEnd = maxReach;
      }
    }

    return jumps;
  }
};
