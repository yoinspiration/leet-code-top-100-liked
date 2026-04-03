#include <unordered_map>

using namespace std;

class LRUCache
{
private:
  struct Node
  {
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
  };

  int capacity_;
  unordered_map<int, Node *> map_;
  Node *head_; // 虚拟头：head_->next 是最近使用
  Node *tail_; // 虚拟尾：tail_->prev 是最久未使用

  void removeNode(Node *node)
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addToFront(Node *node)
  {
    node->next = head_->next;
    node->prev = head_;
    head_->next->prev = node;
    head_->next = node;
  }

  void moveToFront(Node *node)
  {
    removeNode(node);
    addToFront(node);
  }

  void evictIfNeeded()
  {
    if ((int)map_.size() <= capacity_)
    {
      return;
    }

    Node *lru = tail_->prev;
    removeNode(lru);
    map_.erase(lru->key);
    delete lru;
  }

public:
  LRUCache(int capacity) : capacity_(capacity)
  {
    head_ = new Node(0, 0);
    tail_ = new Node(0, 0);
    head_->next = tail_;
    tail_->prev = head_;
  }

  int get(int key)
  {
    auto it = map_.find(key);
    if (it == map_.end())
    {
      return -1;
    }

    Node *node = it->second;
    moveToFront(node);
    return node->value;
  }

  void put(int key, int value)
  {
    auto it = map_.find(key);
    if (it != map_.end())
    {
      Node *node = it->second;
      node->value = value;
      moveToFront(node);
      return;
    }

    Node *node = new Node(key, value);
    map_[key] = node;
    addToFront(node);
    evictIfNeeded();
  }

  ~LRUCache()
  {
    Node *curr = head_;
    while (curr != nullptr)
    {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
  }
};

