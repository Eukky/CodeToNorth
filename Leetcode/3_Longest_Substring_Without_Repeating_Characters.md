# 3. 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。  
示例 1:

```md
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

示例 2:

```md
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

示例 3:

```md
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

## 滑动窗口法

每一次循环都将新的字母放入`unordered_set`中，并且寻找当前字母是否已经存在，如果存在就将当前字母移除，并且左指针加`1`（窗口左边向右移动一格）,记录窗口移动过程中的最大值。

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ss;
        int res = 0;
        int left = 0;
        for(int i = 0; i < s.size(); ++i){
            while(ss.find(s[i]) != ss.end()){
                ss.erase(s[left]);
                left++;
            }
            res = max(res, i - left + 1);
            ss.insert(s[i]);
        }
        return res;
    }
};
```
