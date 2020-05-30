# 680. 验证回文字符串 Ⅱ

给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

> 示例 1:
>
> 输入: "aba"
> 
> 输出: True


> 示例 2:
>
> 输入: "abca"
> 
> 输出: True
> 
> 解释: 你可以删除c字符。


注意:字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。


## 题解
为了判断字符串是否为回文字符串，只要设置两个指针，分别指向字符串的头和尾，然后向中间遍历，若字符对均相等，说明为回文串。本题允许最多删除一个字符，因此若遇到$s[i] != s[j]$，我们还需要分别判断删除$s[i]$或$s[j]$后的字符串是否为回文串。


### Python 版本

```python
# 双指针，逐个比较
class Solution:
    def validPalindrome(self, s: str) -> bool:
        def isPalindrome(low,high):
            i = low
            j = high
            while i < j:
                if s[i] == s[j]:
                    i += 1
                    j -= 1
                else:
                    return False
            return True
        
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                return isPalindrome(i, j-1) or isPalindrome(i+1,j)
        return True
```

```python
# 直接用 “==” 判断两字符串是否相等，速度更快
class Solution:
    def validPalindrome(self, s: str) -> bool:
        if s == s[::-1]:
            return True
        
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                break
        temp1 = s[i:j]
        temp2 = s[i+1:j+1]
        if temp1 == temp1[::-1] or temp2 == temp2[::-1]:
            return True
        else:
            return False
```