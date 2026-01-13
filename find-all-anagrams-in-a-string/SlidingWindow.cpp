class Solution
{
public:
  /**
   * @brief 找到字符串中所有字母异位词的起始位置
   * 
   * @param s 主字符串
   * @param p 模式字符串
   * @return vector<int> 所有字母异位词的起始索引
   */
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> result;
    int sLen = s.length();
    int pLen = p.length();
    
    if (sLen < pLen)
    {
      return result;
    }

    // 使用数组记录字符频率（假设都是小写字母）
    vector<int> pCount(26, 0); // 模式字符串的字符频率
    vector<int> windowCount(26, 0); // 滑动窗口的字符频率

    // 初始化：统计模式字符串和第一个窗口的字符频率
    for (int i = 0; i < pLen; i++)
    {
      pCount[p[i] - 'a']++;
      windowCount[s[i] - 'a']++;
    }

    // 如果第一个窗口匹配，记录索引 0
    if (pCount == windowCount)
    {
      result.push_back(0);
    }

    // 滑动窗口：每次移动一个位置
    for (int i = pLen; i < sLen; i++)
    {
      // 移除窗口左边的字符
      windowCount[s[i - pLen] - 'a']--;
      // 添加窗口右边的字符
      windowCount[s[i] - 'a']++;

      // 检查当前窗口是否匹配
      if (pCount == windowCount)
      {
        result.push_back(i - pLen + 1);
      }
    }

    return result;
  }
};
