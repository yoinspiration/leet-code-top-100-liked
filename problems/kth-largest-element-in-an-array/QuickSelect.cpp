#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution
{
  // 3-way partition (Dutch National Flag): splits [lo,hi] into < pivot | == pivot | > pivot.
  // Returns {lt, gt} where nums[lt..gt] == pivot after partition.
  pair<int, int> partition3(vector<int>& nums, int lo, int hi)
  {
    int pivotIdx = lo + rand() % (hi - lo + 1);
    swap(nums[pivotIdx], nums[lo]);
    int pivot = nums[lo];
    int lt = lo, i = lo + 1, gt = hi;
    while (i <= gt)
    {
      if (nums[i] < pivot)      swap(nums[lt++], nums[i++]);
      else if (nums[i] > pivot) swap(nums[i], nums[gt--]);
      else                      i++;
    }
    return {lt, gt};
  }

public:
  int findKthLargest(vector<int>& nums, int k)
  {
    int target = (int)nums.size() - k; // kth largest = (n-k)th smallest
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo < hi)
    {
      auto [lt, gt] = partition3(nums, lo, hi);
      if (target < lt)      hi = lt - 1;
      else if (target > gt) lo = gt + 1;
      else                  break; // target falls in the == pivot range
    }
    return nums[target];
  }
};
