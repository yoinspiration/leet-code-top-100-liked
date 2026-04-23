#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    // min-heap keyed by frequency, size capped at k
    using P = pair<int, int>; // {freq, val}
    priority_queue<P, vector<P>, greater<P>> minHeap;

    for (auto& [val, cnt] : freq)
    {
      minHeap.push({cnt, val});
      if ((int)minHeap.size() > k)
        minHeap.pop();
    }

    vector<int> res;
    while (!minHeap.empty())
    {
      res.push_back(minHeap.top().second);
      minHeap.pop();
    }
    return res;
  }
};
