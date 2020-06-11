# 38. 字符串的排列

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串`abc`，则打印出由字符`a,b,c`所能排列出来的所有字符串`abc,acb,bac,bca,cab和cba`。  
输入描述:  
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

## 题解

1. 求所有可能出现在第一个位置的字符，即把第一个字符与后面的所有字符交换。
2. 固定第一个字符，求后面所有字符的排列。

### C++

```cpp
class Solution {
    void PermutationHelper(string str, vector<string> &res, int begin, int end){
        if(str.size() == 0){
            return;
        }
        if(begin == end){
            if(find(res.begin(), res.end(), str) == res.end()){
                res.push_back(str);
            }
        }
        for(int i = begin; i < end; ++i){
            swap(str[i], str[begin]);
            //固定第一个字符，对后面的字符进行全排列
            PermutationHelper(str, res, begin + 1, end);
            swap(str[i], str[begin]);
        }
    }
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        PermutationHelper(str, res, 0, str.size());
        sort(res.begin(), res.end());
        return res;
    }
};
```
