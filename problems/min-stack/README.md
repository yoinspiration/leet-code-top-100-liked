# Min Stack

## 解法：辅助最小栈 [MinStack.cpp](MinStack.cpp)

### 算法思路

用两个栈并行维护：
- `st`：正常存储所有元素
- `minSt`：每次 `push` 时同步压入当前最小值（`min(val, minSt.top())`）

两栈始终等高，`pop` 时同步弹出。`getMin()` 直接返回 `minSt.top()`。

### 复杂度分析

- **时间复杂度：O(1)**，所有操作均为常数时间
- **空间复杂度：O(n)**
