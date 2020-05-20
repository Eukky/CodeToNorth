# 1248. 统计「优美子数组」

给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。


> 示例 1：
> 
> 输入：nums = [1,1,2,1,1], k = 3
> 
> 输出：2
> 
> 解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。

> 示例 2：
> 
> 输入：nums = [2,4,6], k = 1
> 
> 输出：0
> 
> 解释：数列中不包含任何奇数，所以不存在优美子数组。


> 示例 3：
> 
> 输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
> 输出：16
 

> 提示：
> 
> 1 <= nums.length <= 50000
> 
> 1 <= nums[i] <= 10^5
> 
> 1 <= k <= nums.length


## 题解
假设 `pre[i]` 表示`nums[0:i+1]`中奇数的个数，那么`pre[i]-pre[j]`表示`nums[j+1:i+1]`中奇数的个数。我们要找到恰好包含 `k` 个奇数的子数组，也就是要找到满足
`pre[i] - pre[j] = k` 的 `i`和`j`，变形可得到`pre[j] = pre[i] - k`。遍历数组，求得`pre[i]`，并将`pre[i]`存入哈希表中，键为`pre[i]`，值为其出现的字数，一旦`pre[i] - k` 已经存在于哈希表中，说明找到了`hashmap[pre[i] - k]` 个包含 `k` 个奇数的子数组。

由于 `pre[j]` 肯定非负，故 `pre[i] - k` 可以不放入哈希表中。

![演示](https://github.com/Eukky/CodeToNorth/blob/Diane/Leetcode/1248.gif)
### Python版本

```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        pre = 0
        hashmap = {0:1}
        cnt = 0
        pre = 0
        for i in range(len(nums)):
            if nums[i] % 2 == 1:
                pre += 1
            if pre - k in hashmap:
                cnt += hashmap[pre-k]
            if pre in hashmap:
                hashmap[pre] += 1
            else:
                hashmap[pre] = 1
        return cnt
```
