# 96. 不同的二叉搜索树

## 题目

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？  
示例:

```md
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

## 动态规划

第`i`个数当作根节点时，左边有`i-1`个节点，右边有`n-i`个节点，因此
$$ dp[n] = \sum^{n}_{i=1}dp(i-1)*dp(n-i) $$

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
```

## 卡塔兰数

该函数的值也被称作卡塔兰数$C_n$
$$ C_{n+1} = \frac{2(2n+1)}{n+2}C_n $$

```cpp
class Solution {
public:
    int numTrees(int n) {
        long c = 1;
        for(int i = 0; i < n; ++i) {
            c = c * 2 * (2 * i + 1) / (i + 2);
        }
        return c;
    }
};
```
