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
   * @brief 160. 相交链表
   *
   * 给你两个单链表的头节点 headA 和 headB，请你找出并返回两个单链表相交的起始节点。
   * 如果两个链表不存在相交节点，返回 nullptr。
   *
   * 核心思想：双指针「对齐长度」
   * - 指针 pA 从 headA 出发，指针 pB 从 headB 出发
   * - pA 走到尾部后跳到 headB，pB 走到尾部后跳到 headA
   * - 如果有相交点，最终会在相交点相遇；如果没有，则同时走到 nullptr
   */
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    if (headA == nullptr || headB == nullptr)
    {
      return nullptr;
    }

    ListNode *pA = headA;
    ListNode *pB = headB;

    // 当 pA 和 pB 第一次走到尾部时，分别切换到另一条链表的头
    // 第二次遍历时，它们走过的总长度相同：lenA + lenB
    // 如果有相交点，会在相交点相遇；否则最终都为 nullptr
    while (pA != pB)
    {
      pA = (pA == nullptr) ? headB : pA->next;
      pB = (pB == nullptr) ? headA : pB->next;
    }

    return pA;
  }
};

