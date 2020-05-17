<head>
    <script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>
    <script type="text/x-mathjax-config">
        MathJax.Hub.Config({
            tex2jax: {
            skipTags: ['script', 'noscript', 'style', 'textarea', 'pre'],
            inlineMath: [['$','$']]
            }
        });
    </script>
</head>

# 03. 数组中重复的数字 
找出数组中重复的数字。

在一个长度为 $n$ 的数组 nums 里的所有数字都在 $0～n-1$ 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

> 示例 1：
> 输入：
> [2, 3, 1, 0, 2, 5, 3]
> 输出：2 或 3 

## 题解
由于nums里的所有数字都在$0~n-1$，我们可构建一个哈希表辅助求解，然而这样做的空间复杂度为$O(n)$。
为了实现$O(1)$的空间复杂度，可以考虑采用原地置换的方式，将原数组重新排序，使得位置$i$的数等于$i$。若$nums[nums[i]] == nums[i]$，$nums[i]$重复了，反之交换二者的位置。


```python
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while nums[i] != i:
                if nums[nums[i]] == nums[i]:
                    return nums[i]
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
```