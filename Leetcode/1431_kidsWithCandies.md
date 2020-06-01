# 1431. 拥有最多糖果的孩子
给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目。

对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目。

 

> 示例 1：
> 
> 输入：candies = [2,3,5,1,3], extraCandies = 3
> 
> 输出：[true,true,true,false,true] 
> 
> 解释：
> 
> 孩子 1 有 2 个糖果，如果他得到所有额外的糖果（3个），那么他总共有 5 个糖果，他将成为拥有最多糖果的孩子。
> 
> 孩子 2 有 3 个糖果，如果他得到至少 2 个额外糖果，那么他将成为拥有最多糖果的孩子。
> 
> 孩子 3 有 5 个糖果，他已经是拥有最多糖果的孩子。
> 
> 孩子 4 有 1 个糖果，即使他得到所有额外的糖果，他也只有 4 个糖果，无法成为拥有糖果最多的孩子。
> 
> 孩子 5 有 3 个糖果，如果他得到至少 2 个额外糖果，那么他将成为拥有最多糖果的孩子。

> 提示：
> 
> 2 <= candies.length <= 100
> 
> 1 <= candies[i] <= 100
> 
> 1 <= extraCandies <= 50

## 题解

这题比较简单，只需先遍历一次`candies`，找到其最大值，再将`candies[i]+extracandies`与`maxCandies`比较即可。

### Python版本
```python
# 利用python特性简化书写，两种方式均可
# 当然也可以直接用for循环求res数组
class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxCandies = max(candies)
        res = [c + extraCandies >= maxCandies for c in candies]
        # res = [True if c + extraCandies >= maxCandies else False for c in candies]
        return res
```