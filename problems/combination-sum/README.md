# 39. 组合总和

https://leetcode.cn/problems/combination-sum/

## 题目

给你一个**无重复元素**的整数数组 `candidates` 和一个目标整数 `target`，找出所有可以使数字和为 `target` 的组合。`candidates` 中的同一个数字可以**无限制重复**选取。

**示例：**
```
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
```

## 思路：回溯 + 剪枝

与子集的区别：
- 子集：每个元素最多选一次，递归传 `i + 1`
- 组合总和：同一元素可重复选，递归传 `i`（不推进起点）

```
candidates = [2,3,6,7], target = 7
backtrack(start=0, remain=7, path=[])
  选2 → backtrack(start=0, remain=5, path=[2])
    选2 → backtrack(start=0, remain=3, path=[2,2])
      选2 → backtrack(start=0, remain=1, path=[2,2,2])
        选2 → remain=-1，剪枝
      选3 → backtrack(start=1, remain=0, path=[2,2,3]) → 记录
      选6 → remain<0，break
    选3 → backtrack(start=1, remain=2, path=[2,3])
      选3 → remain<0，break
    选6 → remain<0，break
  选3 → ...
  选7 → backtrack(start=3, remain=0, path=[7]) → 记录
```

- **排序**：先排序，使得 `candidates[i] > remain` 时可以直接 `break`
- **剪枝**：当前元素超过剩余值，后续更大的元素也不必尝试
- **去重**：用 `start` 控制只往后选，避免 `[2,3]` 和 `[3,2]` 重复

## 实现

- [回溯](Backtracking.cpp)

## 复杂度

- 时间：O(n × target/min)，搜索树节点数
- 空间：O(target/min)，递归栈深度（min 为最小候选值）
