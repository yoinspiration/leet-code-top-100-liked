#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 238. 除自身以外数组的乘积
   *
   * 返回数组 answer，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
   * 要求：时间复杂度 O(n)，不使用除法。
   *
   * 思路：answer[i] = 左侧所有元素乘积 × 右侧所有元素乘积
   */
  vector<int> productExceptSelf(const vector<int> &nums)
  {
    const int n = nums.size();
    vector<int> result(n);

    // 第一遍：result[i] = 位置 i 左侧所有元素的乘积
    result[0] = 1;
    for (int i = 1; i < n; i++)
    {
      result[i] = result[i - 1] * nums[i - 1];
    }

    // 第二遍：从左到右乘上「右侧乘积」
    int suffix = 1; // 当前字符右侧所有元素的乘积
    for (int i = n - 1; i >= 0; i--)
    {
      result[i] *= suffix;
      suffix *= nums[i];
    }

    return result;
  }
};
