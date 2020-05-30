# 63. 股票的最大利润
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

> 示例 1:
> 
> 输入: [7,1,5,3,6,4]
>
> 输出: 5
>
> 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

>示例 2:
>
>输入: [7,6,4,3,1]
>
>输出: 0
>
>解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

## 题解

想要利润最大化，必然需要在最低点买入，在最高点卖出，且卖出日在买入日之后。假设我们卖出是时间固定了，也就是在第 $i$ 天卖出了，那么我们只要找到第$i$天之前的最低价，就可以求出最大利润了。因此，我们只要不断去求第$i$天卖出时的最大利润即可。时间复杂度为$O(n)$，空间复杂度为$O(1)$

### Python版本

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices == []:
            return 0
        minPrice = prices[0]
        res = 0
        for i in range(1,len(prices)):
            if prices[i] < minPrice:
                minPrice = prices[i]
            else:
                res = max(res, prices[i] - minPrice)
        return res
```
