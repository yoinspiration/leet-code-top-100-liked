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
   * @brief 19. 删除链表的倒数第 N 个结点
   *
   * 给你一个链表，删除链表的倒数第 n 个结点，并返回链表的头结点。
   *
   * 核心思想：哑结点 + 快慢指针
   * - fast 先从哑结点出发向前走 n+1 步（或等价写法），使 slow 最终停在待删结点的前驱
   * - 再同时移动 slow、fast，直到 fast 为空
   * - 删除 slow->next
   */
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *slow = &dummy;
    ListNode *fast = &dummy;

    for (int i = 0; i <= n; i++)
    {
      fast = fast->next;
    }

    while (fast != nullptr)
    {
      slow = slow->next;
      fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy.next;
  }
};
