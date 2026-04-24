#include <queue>

using namespace std;

/**
 * @brief 295. 数据流的中位数
 *
 * 维护两个堆：
 *   - maxHeap（大根堆）：存较小的一半，堆顶为下半最大值
 *   - minHeap（小根堆）：存较大的一半，堆顶为上半最小值
 *
 * 不变量：maxHeap.size() == minHeap.size()  或
 *          maxHeap.size() == minHeap.size() + 1
 * 即总数为奇数时，中位数在 maxHeap 堆顶。
 */
class MedianFinder
{
  priority_queue<int> maxHeap;                            // 下半，大根堆
  priority_queue<int, vector<int>, greater<int>> minHeap; // 上半，小根堆

public:
  MedianFinder() {}

  void addNum(int num)
  {
    maxHeap.push(num);
    minHeap.push(maxHeap.top());
    maxHeap.pop();

    if (minHeap.size() > maxHeap.size())
    {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double findMedian()
  {
    if (maxHeap.size() > minHeap.size())
    {
      return maxHeap.top();
    }
    return (maxHeap.top() + minHeap.top()) / 2.0;
  }
};
