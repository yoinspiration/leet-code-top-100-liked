#include <vector>

using namespace std;

class Solution
{
public:
  /**
   * @brief 将数组向右轮转 k 个位置（使用额外数组）
   *
   * 算法思路：
   * 1. 创建一个新数组存储结果
   * 2. 对于原数组位置 i，新位置为 (i + k) % n
   * 3. 将新数组复制回原数组
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

    // 创建新数组存储结果
    vector<int> result(n);

    // 对于原数组位置 i，新位置为 (i + k) % n
    for (int i = 0; i < n; i++)
    {
      result[(i + k) % n] = nums[i];
    }

    // 将结果复制回原数组
    nums = result;
  }
};
