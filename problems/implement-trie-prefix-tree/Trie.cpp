#include <array>
#include <string>

using namespace std;

class Trie
{
public:
  /**
   * @brief 208. 实现 Trie（前缀树）
   *
   * 每个结点有 26 个子指针（对应 'a'~'z'）和一个标记 is_end，
   * 表示是否有单词在此结束。insert/search/startsWith 均沿字符路径逐层向下。
   */
  Trie() : is_end_(false), children_({}) {}

  void insert(const string &word)
  {
    Trie *node = this;
    for (char c : word)
    {
      int idx = c - 'a';
      if (node->children_[idx] == nullptr)
      {
        node->children_[idx] = new Trie();
      }
      node = node->children_[idx];
    }
    node->is_end_ = true;
  }

  bool search(const string &word)
  {
    const Trie *node = find(word);
    return node != nullptr && node->is_end_;
  }

  bool startsWith(const string &prefix)
  {
    return find(prefix) != nullptr;
  }

  ~Trie()
  {
    for (Trie *child : children_)
    {
      delete child;
    }
  }

private:
  bool is_end_;
  array<Trie *, 26> children_;

  const Trie *find(const string &s) const
  {
    const Trie *node = this;
    for (char c : s)
    {
      int idx = c - 'a';
      if (node->children_[idx] == nullptr)
      {
        return nullptr;
      }
      node = node->children_[idx];
    }
    return node;
  }
};
