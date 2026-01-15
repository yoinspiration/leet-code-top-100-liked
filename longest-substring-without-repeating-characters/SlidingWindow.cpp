#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  /**
   * @brief 找到字符串中不含有重复字符的最长子串的长度
   *
   * @param s 输入的字符串
   * @return int 最长子串的长度
   */
  int lengthOfLongestSubstring(string s)
  {
    unordered_map<char, int> charIndex; // 存储字符及其最新出现的位置
    int maxLength = 0;
    int left = 0; // 滑动窗口的左边界

    for (int right = 0; right < s.length(); right++)
    {
      char currentChar = s[right];

      // 如果当前字符在窗口内已经存在（且位置 >= left），更新左边界
      if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left)
      {
        left = charIndex[currentChar] + 1;
      }

      // 更新字符的最新位置
      charIndex[currentChar] = right;

      // 更新最大长度
      maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};
