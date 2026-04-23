#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    int n = nums.size();
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    // bucket[i] holds all elements whose frequency is exactly i
    vector<vector<int>> bucket(n + 1);
    for (auto& [val, cnt] : freq)
      bucket[cnt].push_back(val);

    vector<int> res;
    for (int i = n; i >= 1 && (int)res.size() < k; i--)
      for (int val : bucket[i])
        if ((int)res.size() < k)
          res.push_back(val);

    return res;
  }
};
