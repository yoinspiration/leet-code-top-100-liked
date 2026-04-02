using namespace std;

// LeetCode 会提供 ListNode 的定义，这里仅作注释说明：
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
  /**
   * @brief 24. 两两交换链表中的节点
   *
   * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
   * 你必须在不修改节点值的情况下完成本题（只能进行节点交换）。
   *
   * 核心思想：哑结点 + 指针重连
   * - prev 始终指向当前待交换这对节点之前的节点
   * - 每轮交换 first 与 second，再把 prev 前移到新尾部 first
   */
  ListNode *swapPairs(ListNode *head)
  {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    while (prev->next != nullptr && prev->next->next != nullptr)
    {
      ListNode *first = prev->next;
      ListNode *second = first->next;

      // 交换 first 与 second
      first->next = second->next;
      second->next = first;
      prev->next = second;

      prev = first;
    }

    return dummy.next;
  }
};

