#include <string>
using namespace std;

class Solution
{
public:
  /**
   * @brief 76. 最小覆盖子串
   *
   * 在字符串 s 中找到包含字符串 t 所有字符的最小子串（包含字符次数）。
   * 如果不存在这样的子串，返回空字符串 ""。
   */
  string minWindow(string s, string t)
  {
    if (s.size() < t.size())
    {
      return "";
    }

    // need 记录 t 中每个字符需要多少个
    // window 记录当前窗口中每个字符有多少个
    int need[128] = {0};
    int window[128] = {0};

    int required = 0; // t 中不同字符的种类数
    for (char c : t)
    {
      if (need[(unsigned char)c] == 0)
      {
        required++;
      }
      need[(unsigned char)c]++;
    }

    int formed = 0; // 当前窗口中，满足 need 要求的字符种类数
    int left = 0, right = 0;

    int minLen = INT_MAX; // 最小窗口长度
    int start = 0;        // 最小窗口的起始位置

    while (right < (int)s.size())
    {
      char c = s[right];
      window[(unsigned char)c]++;

      // 如果这个字符是 t 中需要的，并且当前窗口中这个字符的数量
      // 刚好达到 need 的要求，则 "满足的种类数" +1
      if (need[(unsigned char)c] > 0 && window[(unsigned char)c] == need[(unsigned char)c])
      {
        formed++;
      }

      // 当窗口已经覆盖了 t（即所有需要的字符都满足数量要求）时，
      // 尝试收缩左边界，缩小窗口，找最小的那个
      while (formed == required && left <= right)
      {
        // 更新最小窗口
        if (right - left + 1 < minLen)
        {
          minLen = right - left + 1;
          start = left;
        }

        // 收缩窗口左边界
        char d = s[left];
        window[(unsigned char)d]--;

        // 如果 d 是 t 中需要的字符，并且现在窗口中 d 的数量
        // 已经少于需要的数量，那么当前窗口就不再满足条件了
        if (need[(unsigned char)d] > 0 && window[(unsigned char)d] < need[(unsigned char)d])
        {
          formed--;
        }

        left++;
      }

      // 继续扩展右边界
      right++;
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
  }
};

