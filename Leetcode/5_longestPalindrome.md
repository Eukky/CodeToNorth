# 5. 最长回文子串

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

> 示例 1：
>
> 输入: "babad"
>
> 输出: "bab"
>
> 注意: "aba" 也是一个有效答案。
>
> 示例 2：
>
> 输入: "cbbd"
>
> 输出: "bb"

## 题解

首先，只含一个字符的字符串一定是回文串，也就是说`s[i]`一定是回文串。若`s[i-1] = s[i+1]`，则`s[i-1,i+1]`也是回文串，反之不是，且以`s[i-1,i+1]`为中心的子串也不是回文串。根据此思路，我们遍历原字符串中的每个字符，在以当前字符为中心，向两边展开，判断以当前字符为中心的字符串是否为回文串，就可以逐步找到最长的子回文串。

然而，上述做法仅对长度为奇数的子字符串进行了操作，未考虑长度为偶数的子字符串。因此我们还需找到长度为`2`的子回文串，然后再向两边展开，探索以其为中心的子字符串是否为回文串。

### C++

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0 | s.size() == 1){
            return s;
        }
        vector<vector <bool>> dp(s.size(), vector<bool>(s.size(), false));
        int start = 0;
        int end = 0;
        int max = 1;
        string result;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j >= 0; j--){
                if(i == j){
                    dp[j][i] = true;
                    continue;
                }
                if(s[i] == s[j]){
                    if(i - j == 1){
                        dp[j][i] = true;
                    }else{
                        dp[j][i] = dp[j+1][i-1];
                    }
                }
                if(dp[j][i] && i - j + 1 > max){
                    start = j;
                    end = i;
                    max = i - j + 1;
                }
            }
        }
        for(int i = start; i <= end; i++){
            result += s[i];
        }
        return result;
    }
};

```

### Python

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def helper(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                    left -= 1
                    right += 1
            return left+1,right-1

        start, end = 0, 0
        for i in range(len(s)-1):
            left, right = helper(i,i)
            if right - left > end - start:
                start, end = left, right
            left, right = helper(i,i+1)
            if right - left > end - start:
                start, end = left, right
        return s[start:end+1]
```
