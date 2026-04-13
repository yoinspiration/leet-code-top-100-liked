# Implement Trie (Prefix Tree)

实现 Trie（前缀树）

## 题目要求

实现一个 Trie，支持以下操作：
- `insert(word)`：插入字符串。
- `search(word)`：返回字符串是否完整存在于 Trie 中。
- `startsWith(prefix)`：返回是否存在以 `prefix` 为前缀的字符串。

题目链接：[208. 实现 Trie（前缀树）](https://leetcode.cn/problems/implement-trie-prefix-tree/)

## 解法：数组子指针 [Trie.cpp](Trie.cpp)

每个结点存：
- `children_[26]`：指向 26 个小写字母子结点的指针数组，`nullptr` 表示该字符路径不存在。
- `is_end_`：标记是否有单词在此结点结束。

**三个操作均复用私有 `find` 方法**，沿字符路径逐层向下：
- `insert`：路径上缺失的结点即时创建，最后置 `is_end_ = true`。
- `search`：`find` 到末尾后还需检查 `is_end_`，区分"完整单词"与"仅是前缀"。
- `startsWith`：`find` 能走到末尾即可，不要求 `is_end_`。

| 操作 | 时间复杂度 | 空间复杂度 |
|------|-----------|-----------|
| insert | O(\|word\|) | O(\|word\|) 最坏新建结点 |
| search | O(\|word\|) | O(1) |
| startsWith | O(\|prefix\|) | O(1) |

总空间：O(ΣΣΣΣ \|word\|)，与插入的字符总数成正比。
