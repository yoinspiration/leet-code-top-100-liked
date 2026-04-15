#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 22. 括号生成
   *
   * 回溯：用 open/close 分别记录已放的左右括号数。
   * - open < n 时可放左括号
   * - close < open 时可放右括号（保证右括号不超过左括号）
   * - open == close == n 时记录结果
   */
  vector<string> generateParenthesis(int n)
  {
    vector<string> result;
    string path;
    backtrack(n, 0, 0, path, result);
    return result;
  }

private:
  void backtrack(int n, int open, int close,
                 string &path, vector<string> &result)
  {
    if (open == n && close == n)
    {
      result.push_back(path);
      return;
    }
    if (open < n)
    {
      path.push_back('(');
      backtrack(n, open + 1, close, path, result);
      path.pop_back();
    }
    if (close < open)
    {
      path.push_back(')');
      backtrack(n, open, close + 1, path, result);
      path.pop_back();
    }
  }
};
