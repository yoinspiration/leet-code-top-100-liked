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
   * @brief 21. 合并两个有序链表
   *
   * 将两个升序链表合并为一个新的升序链表并返回。新链表由拼接两链表节点组成。
   *
   * 核心思想：哑结点 + 双指针
   * - 用 dummy 简化头结点处理，tail 始终指向结果链表的尾
   * - 每次比较 list1、list2 当前结点值，较小者接到 tail 后并前移对应指针
   */
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
      if (list1->val <= list2->val)
      {
        tail->next = list1;
        list1 = list1->next;
      }
      else
      {
        tail->next = list2;
        list2 = list2->next;
      }
      tail = tail->next;
    }

    tail->next = (list1 != nullptr) ? list1 : list2;
    return dummy.next;
  }
};
