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
private:
  // 合并两条有序链表，返回新头节点
  ListNode *merge(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (l1 != nullptr && l2 != nullptr)
    {
      if (l1->val <= l2->val)
      {
        tail->next = l1;
        l1 = l1->next;
      }
      else
      {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    tail->next = (l1 != nullptr) ? l1 : l2;
    return dummy.next;
  }

public:
  /**
   * @brief 148. 排序链表
   *
   * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行升序排序。
   *
   * 核心思想：归并排序（自顶向下）
   * - 快慢指针找中点，断开为左右两半
   * - 递归排序左右子链表
   * - 合并两条有序链表
   */
  ListNode *sortList(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }

    // 找中点：slow 最终停在中点左侧（用于断链）
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *rightHead = slow->next;
    slow->next = nullptr; // 断开左右两段

    ListNode *leftSorted = sortList(head);
    ListNode *rightSorted = sortList(rightHead);
    return merge(leftSorted, rightSorted);
  }
};

