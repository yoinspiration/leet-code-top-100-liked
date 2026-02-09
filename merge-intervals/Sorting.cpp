#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 合并所有重叠的区间
   *
   * 算法思路：
   * 1. 先按区间的左端点排序
   * 2. 遍历排序后的区间，如果当前区间与结果中的最后一个区间重叠，则合并
   * 3. 否则，将当前区间加入结果
   *
   * @param intervals 区间数组，每个区间 [start, end]
   * @return vector<vector<int>> 合并后的区间数组
   */
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    // 如果区间数组为空或只有一个区间，直接返回
    if (intervals.size() <= 1)
    {
      return intervals;
    }

    // 按区间的左端点（第一个元素）排序
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
           return a[0] < b[0];
         });

    vector<vector<int>> result;
    result.push_back(intervals[0]); // 将第一个区间加入结果

    // 遍历剩余的区间
    for (int i = 1; i < intervals.size(); i++)
    {
      // 获取结果中最后一个区间和当前区间
      vector<int> &last = result.back();
      const vector<int> &current = intervals[i];

      // 如果当前区间的左端点 <= 最后一个区间的右端点，说明重叠
      // 例如：[1,3] 和 [2,6] 重叠，因为 2 <= 3
      if (current[0] <= last[1])
      {
        // 合并：更新最后一个区间的右端点为两者的最大值
        // 例如：[1,3] 和 [2,6] 合并为 [1,6]
        last[1] = max(last[1], current[1]);
      }
      else
      {
        // 不重叠，将当前区间加入结果
        result.push_back(current);
      }
    }

    return result;
  }
};
