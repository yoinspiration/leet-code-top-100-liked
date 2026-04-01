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
   * @brief 234. 回文链表
   *
   * 判断一个链表是否为回文链表。
   *
   * 核心思想：快慢指针 + 反转后半部分 + 比较
   * 1. 使用快慢指针找到链表中点（slow）
   * 2. 反转从中点开始的后半部分链表
   * 3. 从头和中点分别向后比较节点值
   * 4. （可选）恢复链表结构
   */
  bool isPalindrome(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return true;
    }

    // 1. 使用快慢指针找到中点
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // 2. 反转后半部分链表（从 slow 开始）
    ListNode *prev = nullptr;
    ListNode *cur = slow;
    while (cur != nullptr)
    {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    // 此时 prev 指向反转后半部分的头结点

    // 3. 从两端向中间比较
    ListNode *p1 = head;
    ListNode *p2 = prev;
    while (p2 != nullptr)
    {
      if (p1->val != p2->val)
      {
        return false;
      }
      p1 = p1->next;
      p2 = p2->next;
    }

    return true;
  }
};

