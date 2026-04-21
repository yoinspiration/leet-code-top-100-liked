#include <vector>

using namespace std;

class Solution
{
  int lowerBound(const vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return left;
  }

public:
  vector<int> searchRange(const vector<int> &nums, int target)
  {
    int first = lowerBound(nums, target);
    if (first == (int)nums.size() || nums[first] != target)
      return {-1, -1};

    int last = lowerBound(nums, target + 1) - 1;
    return {first, last};
  }
};
