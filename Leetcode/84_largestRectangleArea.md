# 84. 柱状图中最大的矩形


## 题解
**方法1.** 暴力法。 可先固定高度，然后求在此高度下，矩形的最大宽度。那么只要两边的柱形高度比当前的柱形高度高，左右边界就可以一直向两边扩展。

**方法2.** 利用栈优化，以空间换时间。同样先固定高度，只不过利用一个栈来存错已经遍历到的柱子的下标，并使得栈内的柱子的高度非递减。也就是当遇到比栈顶柱子矮的柱子，就要弹出栈内所有不低于该柱子的柱子下标，且这些柱子的右边界为`i`。那么左边界该如何确当呢？由于在遍历柱子时，我们维护了一个高度非递减的栈，因此柱子`i`的左边界就等于当前的栈顶元素。
   
### Python版本

```Python
# 暴力法，固定高度
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        if heights == []:
            return 0
        N = len(heights)
        res = 0
        for i in range(N):
            left, right = i, i
            while left >= 0 and heights[left] >= heights[i]:
                left -= 1
            while right < N and heights[right] >= heights[i]:
                right += 1
            res = max(res, (right-left-1)*heights[i])
        return res
```

```Python
# 利用栈优化
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        if heights == []:
            return 0
        N = len(heights)
        left, right = [0]*N, [N]*N
        stack = []
        for i in range(N):
            while stack != [] and heights[i] <= heights[stack[-1]]:
                right[stack[-1]] = i
                stack.pop()
            left[i] = stack[-1] if stack else -1
            stack.append(i)
        res = 0
        for i in range(N):
            res = max(res, heights[i]*(right[i] - left[i] - 1))
        return res
```