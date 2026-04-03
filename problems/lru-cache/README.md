# LRU Cache

LRU 缓存

## 题目要求

实现 `LRUCache` 类：

- `LRUCache(int capacity)`：以正整数容量 `capacity` 初始化缓存
- `int get(int key)`：若 key 存在返回 value，否则返回 `-1`
- `void put(int key, int value)`：插入或更新 key；若超容量，淘汰最近最少使用（LRU）项

要求 `get` 和 `put` 的平均时间复杂度为 `O(1)`。

## 解法：哈希表 + 双向链表 [HashMapAndDoublyLinkedList.cpp](HashMapAndDoublyLinkedList.cpp)

### 算法思路

**核心结构：**

- `unordered_map<int, Node*>`：`key -> 节点地址`，用于 O(1) 定位
- 双向链表：维护使用顺序
  - 头部附近：最近使用（MRU）
  - 尾部附近：最久未使用（LRU）

使用虚拟头尾节点可统一插入/删除逻辑。

**操作规则：**

- `get(key)`：
  - 若不存在，返回 `-1`
  - 若存在，把该节点移动到链表头部，再返回值
- `put(key, value)`：
  - 若 key 已存在：更新值并移到头部
  - 若 key 不存在：新建节点插到头部，并放入哈希表
  - 若容量超限：删除尾部前一个真实节点（LRU），并从哈希表移除

### 复杂度分析

- **时间复杂度：**
  - `get` 平均 `O(1)`
  - `put` 平均 `O(1)`
- **空间复杂度：O(capacity)**

### 解法评价

这是该题最经典、面试中最常见的实现方式。只用哈希表无法维护最近使用顺序，只用链表又无法 O(1) 定位，二者组合才能满足题目要求。

