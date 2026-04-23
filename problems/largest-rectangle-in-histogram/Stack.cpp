#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int>& heights)
  {
    int n = heights.size();
    int maxArea = 0;
    stack<int> st; // indices, monotonic increasing by height

    for (int i = 0; i <= n; i++)
    {
      int cur = (i == n) ? 0 : heights[i];
      while (!st.empty() && heights[st.top()] > cur)
      {
        int h = heights[st.top()]; st.pop();
        int w = st.empty() ? i : (i - st.top() - 1);
        maxArea = max(maxArea, h * w);
      }
      st.push(i);
    }
    return maxArea;
  }
};
