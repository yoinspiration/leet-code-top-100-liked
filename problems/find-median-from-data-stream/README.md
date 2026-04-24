# Find Median from Data Stream

数据流的中位数

## 题目要求

设计一个支持以下两种操作的数据结构：

- `addNum(num)`：将一个整数加入数据流。
- `findMedian()`：返回目前所有已加入数字的中位数。

若数字个数为偶数，中位数定义为中间两个数的平均值。

## 解法：双堆（大根堆 + 小根堆） [TwoHeaps.cpp](TwoHeaps.cpp)

### 算法思路

用两个堆将数据流划分为"下半"和"上半"两部分：

- **maxHeap（大根堆）**：存放较小的一半元素，堆顶是下半的最大值。
- **minHeap（小根堆）**：存放较大的一半元素，堆顶是上半的最小值。

维护不变量：`maxHeap.size() == minHeap.size()` 或 `maxHeap.size() == minHeap.size() + 1`。

`addNum` 的步骤：
1. 先将新数插入 `maxHeap`，再把 `maxHeap` 堆顶移入 `minHeap`（保证 `minHeap` 中的所有元素 ≥ `maxHeap` 中的所有元素）。
2. 若 `minHeap` 大小超过 `maxHeap`，则将 `minHeap` 堆顶移回 `maxHeap`，恢复不变量。

`findMedian` 的步骤：
- 总数为奇数时，返回 `maxHeap.top()`。
- 总数为偶数时，返回 `(maxHeap.top() + minHeap.top()) / 2.0`。

### 复杂度分析

- **时间复杂度：addNum O(log n)，findMedian O(1)**
- **空间复杂度：O(n)**，两个堆共存储所有元素。

### 解法评价

双堆是本题最经典的解法，以 O(log n) 的插入代价换取 O(1) 的查询，适合数据量大、查询频繁的场景。
