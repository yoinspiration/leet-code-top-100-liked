#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int findKthLargest(vector<int>& nums, int k)
  {
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap of size k

    for (int x : nums)
    {
      minHeap.push(x);
      if ((int)minHeap.size() > k)
        minHeap.pop();
    }
    return minHeap.top();
  }
};
