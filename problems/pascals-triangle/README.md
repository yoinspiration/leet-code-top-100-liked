# Pascal's Triangle

杨辉三角

## 题目要求

给定一个非负整数 `numRows`，生成「杨辉三角」的前 `numRows` 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

**示例：**

```
输入：numRows = 5
输出：[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

## 解法：动态规划 [DynamicProgramming.cpp](DynamicProgramming.cpp)

### 算法思路

逐行构建三角形，利用递推关系填充每行中间元素：

```
triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
```

每行首尾元素初始化为 1，中间位置 `j`（`1 ≤ j < i`）由上一行的相邻两元素相加得到。

### 复杂度分析

- **时间复杂度：O(numRows²)**
  - 共填充 `1 + 2 + ... + numRows = numRows*(numRows+1)/2` 个元素
- **空间复杂度：O(numRows²)**
  - 输出本身占用的空间
