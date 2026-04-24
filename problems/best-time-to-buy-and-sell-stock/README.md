# Best Time to Buy and Sell Stock

买卖股票的最佳时机

## 题目要求

给定一个数组 `prices`，其中 `prices[i]` 表示某支股票第 `i` 天的价格。

你只能选择**某一天**买入这只股票，并选择在**未来的某一个不同的日子**卖出该股票。计算出你所能获取的最大利润。如果你不能获取任何利润，返回 `0`。

**示例：**

```
输入：prices = [7,1,5,3,6,4]
输出：5
解释：在第 2 天（价格 = 1）买入，在第 5 天（价格 = 6）卖出，利润 = 6-1 = 5。

输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下，没有交易完成，所以最大利润为 0。
```

## 解法：动态规划 [DynamicProgramming.cpp](DynamicProgramming.cpp)

### 算法思路

一次遍历，维护两个变量：

- `minPrice`：截止当前见过的最低价格（最佳买入点）
- `maxProfit`：截止当前能获得的最大利润

对于每个价格 `prices[i]`，它的最大利润为 `prices[i] - minPrice`（以历史最低价买入，今天卖出）。更新全局最大利润后，再更新历史最低价。

**状态转移：**
```
maxProfit = max(maxProfit, prices[i] - minPrice)
minPrice  = min(minPrice, prices[i])
```

### 复杂度分析

- **时间复杂度：O(n)** — 单次遍历
- **空间复杂度：O(1)** — 只用常数额外空间

### 解法评价

最优解法。本质是 DP：`dp[i] = prices[i] - min(prices[0..i-1])`，空间优化后只需两个变量。
