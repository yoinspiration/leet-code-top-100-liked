#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> partitionLabels(const string &s)
  {
    int last[26] = {};
    for (int i = 0; i < (int)s.size(); i++)
      last[s[i] - 'a'] = i;

    vector<int> result;
    int start = 0;
    int curEnd = 0;

    for (int i = 0; i < (int)s.size(); i++)
    {
      curEnd = max(curEnd, last[s[i] - 'a']);
      if (i == curEnd)
      {
        result.push_back(curEnd - start + 1);
        start = i + 1;
      }
    }

    return result;
  }
};
