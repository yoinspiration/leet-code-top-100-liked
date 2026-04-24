#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  bool canJump(const vector<int> &nums)
  {
    int maxReach = 0;

    for (int i = 0; i < (int)nums.size(); i++)
    {
      if (i > maxReach)
        return false;
      maxReach = max(maxReach, i + nums[i]);
    }

    return true;
  }
};
