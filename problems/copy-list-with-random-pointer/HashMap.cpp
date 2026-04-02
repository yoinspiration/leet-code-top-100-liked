// LeetCode 会提供 Node 的定义，这里仅作注释说明：
// class Node {
// public:
//   int val;
//   Node* next;
//   Node* random;
//
//   Node(int _val) {
//     val = _val;
//     next = nullptr;
//     random = nullptr;
//   }
// };

#include <unordered_map>

using namespace std;

class Solution
{
public:
  /**
   * @brief 138. 随机链表的复制
   *
   * 给你一个长度为 n 的链表，每个节点包含额外随机指针 random。
   * 请你构造这个链表的深拷贝，返回新链表头结点。
   *
   * 核心思想：哈希表映射「原节点 -> 新节点」
   * - 第一次遍历：复制所有节点值和 next 结构，建立映射
   * - 第二次遍历：根据映射补全 random 指针
   */
  Node *copyRandomList(Node *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }

    unordered_map<Node *, Node *> nodeMap;
    Node *curr = head;

    // 第一次遍历：为每个原节点创建副本节点
    while (curr != nullptr)
    {
      nodeMap[curr] = new Node(curr->val);
      curr = curr->next;
    }

    // 第二次遍历：连接副本节点的 next 和 random
    curr = head;
    while (curr != nullptr)
    {
      nodeMap[curr]->next = (curr->next == nullptr) ? nullptr : nodeMap[curr->next];
      nodeMap[curr]->random = (curr->random == nullptr) ? nullptr : nodeMap[curr->random];
      curr = curr->next;
    }

    return nodeMap[head];
  }
};

