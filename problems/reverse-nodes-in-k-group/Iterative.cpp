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
   * @brief 25. K 个一组翻转链表
   *
   * 每 k 个节点一组进行翻转，若最后不足 k 个则保持原顺序。
   *
   * 核心思想：哑结点 + 分组反转
   * - 每轮先检查从 groupPrev 开始是否还有 k 个节点
   * - 若足够，原地反转该组，并把前后链路重新接好
   */
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (head == nullptr || k <= 1)
    {
      return head;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode *groupPrev = &dummy;

    while (true)
    {
      // 找到本组第 k 个节点（组尾）
      ListNode *kth = groupPrev;
      for (int i = 0; i < k && kth != nullptr; i++)
      {
        kth = kth->next;
      }
      if (kth == nullptr)
      {
        break; // 剩余不足 k 个，不翻转
      }

      ListNode *groupNext = kth->next;
      ListNode *prev = groupNext;
      ListNode *curr = groupPrev->next;

      // 反转 [curr, kth] 这 k 个节点
      while (curr != groupNext)
      {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }

      // 连接前后链路
      ListNode *oldGroupHead = groupPrev->next;
      groupPrev->next = kth;
      groupPrev = oldGroupHead; // oldGroupHead 反转后变为组尾
    }

    return dummy.next;
  }
};

