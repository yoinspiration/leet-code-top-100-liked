class Solution
{
public:
  /**
   * @brief 找到字符串中不含有重复字符的最长子串的长度（暴力枚举解法）
   * 
   * @param s 输入的字符串
   * @return int 最长子串的长度
   */
  int lengthOfLongestSubstring(string s)
  {
    int maxLength = 0;
    int n = s.length();

    // 枚举所有可能的子串起点
    for (int i = 0; i < n; i++)
    {
      unordered_set<char> seen; // 记录当前子串中已出现的字符
      
      // 从起点 i 开始扩展子串
      for (int j = i; j < n; j++)
      {
        // 如果遇到重复字符，停止扩展
        if (seen.find(s[j]) != seen.end())
        {
          break;
        }
        
        seen.insert(s[j]);
        maxLength = max(maxLength, j - i + 1);
      }
    }

    return maxLength;
  }
};
