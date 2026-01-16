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

    // 滑动窗口主循环：right 不断向右扩展
    while (right < (int)s.size())
    {
      // 步骤1：扩展右边界，将 s[right] 加入窗口
      char c = s[right];
      window[(unsigned char)c]++; // 当前窗口中字符 c 的数量 +1

      // 步骤2：检查这个字符是否让某个"种类"刚好满足要求
      // 例如：need['A'] = 1，如果 window['A'] 从 0 变成 1，说明 A 刚好满足要求了
      // 注意：如果 window['A'] 从 1 变成 2，虽然也满足，但不会重复计数 formed
      if (need[(unsigned char)c] > 0 && window[(unsigned char)c] == need[(unsigned char)c])
      {
        formed++; // 又有一个字符种类刚好满足要求了
      }

      // 步骤3：当窗口已经覆盖了 t（formed == required）时，
      // 尝试收缩左边界，尽量缩小窗口，找最小的覆盖子串
      while (formed == required && left <= right)
      {
        // 更新最小窗口（每次窗口满足条件时都尝试更新）
        if (right - left + 1 < minLen)
        {
          minLen = right - left + 1; // 记录更小的窗口长度
          start = left;               // 记录窗口的起始位置
        }

        // 收缩窗口左边界：移除 s[left]
        char d = s[left];
        window[(unsigned char)d]--; // 窗口中字符 d 的数量 -1

        // 检查移除 d 后，是否导致某个字符种类不再满足要求
        // 例如：need['A'] = 1，如果 window['A'] 从 1 变成 0，说明 A 不满足了
        if (need[(unsigned char)d] > 0 && window[(unsigned char)d] < need[(unsigned char)d])
        {
          formed--; // 有一个字符种类不再满足要求了，退出收缩循环
        }

        left++; // 左边界右移
      }

      // 步骤4：继续扩展右边界
      right++;
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
  }
};

