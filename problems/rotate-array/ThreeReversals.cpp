#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 将数组向右轮转 k 个位置（三次反转法，空间 O(1)）
   *
   * 算法思路（三次反转）：
   * 1. 反转整个数组
   * 2. 反转前 k 个元素
   * 3. 反转后 n-k 个元素
   *
   * 例如：nums = [1,2,3,4,5,6,7], k = 3
   * 步骤1：反转整个数组 → [7,6,5,4,3,2,1]
   * 步骤2：反转前 3 个 → [5,6,7,4,3,2,1]
   * 步骤3：反转后 4 个 → [5,6,7,1,2,3,4] ✓
   *
   * @param nums 输入的整数数组
   * @param k 轮转的步数
   */
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    if (n == 0 || k == 0)
    {
      return;
    }

    k = k % n; // 处理 k >= n 的情况（轮转 n 次等于不转）

    // 步骤1：反转整个数组
    reverse(nums.begin(), nums.end());

    // 步骤2：反转前 k 个元素
    reverse(nums.begin(), nums.begin() + k);

    // 步骤3：反转后 n-k 个元素
    reverse(nums.begin() + k, nums.end());
  }
};
