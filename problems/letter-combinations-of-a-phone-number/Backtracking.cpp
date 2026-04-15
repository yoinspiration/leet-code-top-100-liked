#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  /**
   * @brief 17. 电话号码的字母组合
   *
   * 回溯：按数字顺序逐位处理，每位取对应字母集中的一个字母加入路径，
   * 递归处理下一位，路径长度等于 digits 长度时记录结果。
   */
  vector<string> letterCombinations(string digits)
  {
    if (digits.empty())
    {
      return {};
    }
    vector<string> result;
    string path;
    backtrack(digits, 0, path, result);
    return result;
  }

private:
  const unordered_map<char, string> phone = {
      {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  void backtrack(const string &digits, int index,
                 string &path, vector<string> &result)
  {
    if (index == (int)digits.size())
    {
      result.push_back(path);
      return;
    }
    for (char c : phone.at(digits[index]))
    {
      path.push_back(c);
      backtrack(digits, index + 1, path, result);
      path.pop_back();
    }
  }
};
