class Solution
{
public:
  /**
   * @brief 将字符串数组按照字母异位词分组
   *
   * @param strs 输入的字符串数组
   * @return vector<vector<string>> 分组后的字符串数组
   */
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> anagramMap;

    // 遍历每个字符串，将排序后的字符串作为键
    for (const auto &str : strs)
    {
      string sortedStr = str;
      sort(sortedStr.begin(), sortedStr.end());
      anagramMap[sortedStr].push_back(str);
    }

    // 将哈希表中的值收集到结果中
    vector<vector<string>> result;
    for (auto &pair : anagramMap)
    {
      result.push_back(std::move(pair.second));
    }

    return result;
  }
};
