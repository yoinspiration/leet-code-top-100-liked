#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxProfit(const vector<int> &prices)
  {
    int minPrice = prices[0];
    int profit = 0;

    for (int i = 1; i < (int)prices.size(); i++)
    {
      profit = max(profit, prices[i] - minPrice);
      minPrice = min(minPrice, prices[i]);
    }

    return profit;
  }
};
