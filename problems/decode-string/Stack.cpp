#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  string decodeString(string s)
  {
    stack<int> numSt;
    stack<string> strSt;
    string cur;
    int num = 0;

    for (char c : s)
    {
      if (isdigit(c))
      {
        num = num * 10 + (c - '0');
      }
      else if (c == '[')
      {
        numSt.push(num);
        strSt.push(cur);
        num = 0;
        cur = "";
      }
      else if (c == ']')
      {
        int repeat = numSt.top(); numSt.pop();
        string prev = strSt.top(); strSt.pop();
        for (int i = 0; i < repeat; i++)
          prev += cur;
        cur = prev;
      }
      else
      {
        cur += c;
      }
    }
    return cur;
  }
};
