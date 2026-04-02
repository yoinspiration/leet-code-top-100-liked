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
   * @brief 2. 两数相加
   *
   * 给你两个非空的链表，表示两个非负整数；数字最高位在链表末尾，每位是逆序存储。
   * 请你将两数相加，并以相同形式返回一条表示和的链表。
   *
   * 核心思想：哑结点 + 模拟竖式加法
   * - 同时遍历 l1、l2，对应位相加并加上进位 carry
   * - 和为 sum，当前位 sum % 10，进位 sum / 10
   * - 某条链先走完则只加另一条；最后若还有进位，再补一位
   */
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
      int sum = carry;
      if (l1 != nullptr)
      {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr)
      {
        sum += l2->val;
        l2 = l2->next;
      }
      carry = sum / 10;
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
    }

    return dummy.next;
  }
};
