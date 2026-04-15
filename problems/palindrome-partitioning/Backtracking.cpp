#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 131. 分割回文串
   *
   * 回溯：从 start 出发，枚举每个可能的结束位置 end。
   * 若 s[start..end] 是回文串，则加入当前路径并递归处理剩余后缀；
   * 当 start 到达字符串末尾时，当前路径就是一种合法分割方案。
   */
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> result;
    vector<string> path;
    backtrack(s, 0, path, result);
    return result;
  }

private:
  void backtrack(const string &s, int start,
                 vector<string> &path, vector<vector<string>> &result)
  {
    if (start == (int)s.size())
    {
      result.push_back(path);
      return;
    }

    for (int end = start; end < (int)s.size(); end++)
    {
      if (!isPalindrome(s, start, end))
      {
        continue;
      }

      path.push_back(s.substr(start, end - start + 1));
      backtrack(s, end + 1, path, result);
      path.pop_back();
    }
  }

  bool isPalindrome(const string &s, int left, int right)
  {
    while (left < right)
    {
      if (s[left] != s[right])
      {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};
