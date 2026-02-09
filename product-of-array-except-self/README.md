# Product of Array Except Self

除自身以外数组的乘积

## 题目要求

给你一个整数数组 `nums`，返回数组 `answer`，其中 `answer[i]` 等于 `nums` 中除 `nums[i]` 之外其余各元素的乘积。

**要求：** 时间复杂度 O(n)，不使用除法。

**示例：**

```
输入：nums = [1,2,3,4]
输出：[24,12,8,6]

输入：nums = [-1,1,0,-3,3]
输出：[0,0,9,0,0]
```

## 解法：前缀积 + 后缀积 [PrefixProduct.cpp](PrefixProduct.cpp)

### 算法思路

`answer[i]` = 位置 i 左侧所有元素的乘积 × 位置 i 右侧所有元素的乘积。

1. **第一遍（从左到右）**：`result[i]` = 左侧所有元素的乘积
   - `result[0] = 1`（左侧无元素）
   - `result[i] = result[i-1] * nums[i-1]`

2. **第二遍（从右到左）**：用变量 `suffix` 记录右侧乘积，乘到 `result[i]` 上
   - 遍历时更新 `suffix *= nums[i]`

### 复杂度分析

- **时间复杂度：O(n)** - 两遍遍历
- **空间复杂度：O(1)** - 输出数组不计入，只用了常数额外空间（suffix）
