#include <cstddef>

using namespace std;

// LeetCode 会提供 ListNode 的定义，这里仅作注释说明：
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution
{
public:
  /**
   * @brief 141. 环形链表
   *
   * 给你一个链表的头节点 head，判断链表中是否有环。
   *
   * 核心思想：快慢指针（Floyd 判圈算法）
   * - slow 每次走一步，fast 每次走两步
   * - 如果存在环，fast 终会在环内追上 slow（相遇）
   * - 如果不存在环，fast 会先到达 nullptr
   */
  bool hasCycle(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;           // 慢指针走一步
      fast = fast->next->next;     // 快指针走两步

      if (slow == fast)
      {
        return true;               // 在环内相遇，说明有环
      }
    }

    return false;                  // fast 到达链表末尾，说明无环
  }
};

