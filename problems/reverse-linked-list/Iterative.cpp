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
   * @brief 206. 反转链表（迭代法）
   *
   * 给你单链表的头节点 head，请你反转链表，并返回反转后的链表。
   *
   * 核心思想：三指针迭代反转
   * - prev 指向已反转部分的头，cur 指向当前处理的节点，next 保存下一节点
   * - 每一步把 cur->next 指向 prev，然后整体往前推进
   */
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *cur = head;

    while (cur != nullptr)
    {
      ListNode *next = cur->next; // 暂存下一节点
      cur->next = prev;           // 反转指针
      prev = cur;                 // prev 前进
      cur = next;                 // cur 前进
    }

    // prev 此时为新的头节点
    return prev;
  }
};

