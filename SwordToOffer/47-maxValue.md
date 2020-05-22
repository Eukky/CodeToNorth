# 47. 礼物的最大价值

在一个 `m*n` 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？


> 示例 1:
> 
> 输入: 
> [[1,3,1],
>  [1,5,1],
>  [4,2,1]]
>   
> 输出: 12
> 
> 解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

## 题解
假设 `dp[i][j]` 表示抵达位置`(i,j)`时，获得的礼物的最大价值。由于每次只能往右或者往下走，且礼物的价值都是大于零的，因此只要比较到达位置`(i-1,j)`和`(i,j-1)`时所获得礼物的最大价值，再加上位置`(i,j)`的礼物价值，即可得到`dp[i][j]`，也就是说
$$dp[i][j] = \max(dp[i-1][j],dp[i][j-1])+grid[i][j].$$
而当 `i = 0` 时，每次都只能往右走，故有
$$dp[i][j] = dp[i][j-1] + grid[i][j], i = 0.$$
同理当 `j = 0` 时有，
$$dp[i][j] = dp[i-1][j] + grid[i][j], j = 0.$$
综上可得到：
$$dp[i][j]=\left\{\begin{array}{ll}
grid[i][j] & , i=0, j=0 \\
grid[i][j]+dp[i][j-1] & , i=0, j \neq 0 \\
grid[i][j]+dp[i-1][j] & , i \neq 0, j=0 \\
grid[i][j]+\max (dp[i][j-1], dp[i-1][j]) & , i \neq 0, j \neq 0
\end{array}\right.$$

### Python版本

```python
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if List == []:
            return 0
        if len(grid) == 1:
            return sum(grid[0])
        if len(grid[0]) == 1:
            res = 0
            for n in grid:
                res += n[0]
            return res
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        dp[0][0] = grid[0][0]
        for i in range(1,m):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for j in range(1,n):
            dp[0][j] = dp[0][j-1] + grid[0][j]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        return dp[m-1][n-1]

```