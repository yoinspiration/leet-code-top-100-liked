#include <stack>
#include <algorithm>

using namespace std;

class MinStack
{
  stack<int> st;
  stack<int> minSt; // top always holds the current minimum

public:
  void push(int val)
  {
    st.push(val);
    minSt.push(minSt.empty() ? val : min(val, minSt.top()));
  }

  void pop()
  {
    st.pop();
    minSt.pop();
  }

  int top()
  {
    return st.top();
  }

  int getMin()
  {
    return minSt.top();
  }
};
