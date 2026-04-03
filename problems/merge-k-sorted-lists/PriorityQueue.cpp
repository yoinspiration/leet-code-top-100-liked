#include <queue>
#include <vector>

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
   * @brief 23. 合并 K 个升序链表
   *
   * 给你一个链表数组，每个链表都已按升序排列。
   * 请将所有链表合并到一个升序链表中并返回。
   *
   * 核心思想：最小堆维护当前 k 个链表的最小头结点
   * - 先把每条非空链表的头结点入堆
   * - 每次弹出最小节点接到结果链表尾部
   * - 若该节点后继非空，则把后继再入堆
   */
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    struct Compare
    {
      bool operator()(ListNode *a, ListNode *b) const
      {
        return a->val > b->val; // 小根堆
      }
    };

    priority_queue<ListNode *, vector<ListNode *>, Compare> minHeap;
    for (ListNode *node : lists)
    {
      if (node != nullptr)
      {
        minHeap.push(node);
      }
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (!minHeap.empty())
    {
      ListNode *node = minHeap.top();
      minHeap.pop();

      tail->next = node;
      tail = tail->next;

      if (node->next != nullptr)
      {
        minHeap.push(node->next);
      }
    }

    return dummy.next;
  }
};

