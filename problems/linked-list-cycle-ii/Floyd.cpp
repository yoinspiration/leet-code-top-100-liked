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
   * @brief 142. 环形链表 II
   *
   * 给定一个链表的头节点 head，返回链表开始入环的第一个节点。
   * 如果链表无环，则返回 nullptr。
   *
   * 核心思想：Floyd 判圈 + 数学关系定位入环点
   * - 第一步：快慢指针判断是否有环，并找到第一次相遇点
   * - 第二步：一个指针从 head 出发，另一个从相遇点出发
   *          两者每次都走一步，再次相遇的位置就是入环点
   */
  ListNode *detectCycle(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    // 先判断是否存在环
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast)
      {
        // 从头节点与相遇点同时出发，再次相遇即入环点
        ListNode *ptr = head;
        while (ptr != slow)
        {
          ptr = ptr->next;
          slow = slow->next;
        }
        return ptr;
      }
    }

    return nullptr;
  }
};

