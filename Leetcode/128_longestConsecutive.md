# 128. 最长连续序列
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

> 示例:
> 
> 输入: [100, 4, 200, 1, 3, 2]
>
> 输出: 4
>
> 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

## 题解
首先判断对数组去重。然后遍历数组。

若`x-1`不在数组内，继续查看`x+1`，`x+2`等在不在数组内，若在，连续序列的长度加1，若不在，则查看数组中的下一个元素。

若`x-1`在数组内，则跳过该元素。


```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        nums_set = set(nums)

        
        res = 1
        for n in nums_set:
            if n-1 not in nums_set:
                cur = 1
                cur_num = n
                while cur_num + 1 in nums_set:
                    cur += 1
                    cur_num += 1
                res = max(res, cur)
        return res
```