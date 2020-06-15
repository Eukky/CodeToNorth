# 14. 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

```md
输入: ["flower","flow","flight"]
输出: "fl"
```

示例 2:

```md
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
```

说明:所有输入只包含小写字母 a-z 。

## 题解

- 横向扫描

  每一个单词逐一对比，取出公共部分再与下一个单词进行对比。

- 纵向扫描

  以此取出第一个单词的各个字母，与每一个单词进行对比。

### CPP

```cpp
// 横向扫描
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string compare = strs[0];
        int min = compare.size();
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].size() < min){
                if(strs[i] == ""){
                    return "";
                }
                min = strs[i].size();
            }
            for(int j = 0; j < min; j++){
                if(compare == ""){
                    return "";
                }
                if(compare[j] != strs[i][j]){
                    compare = compare.substr(0, j);
                }
                else if(j == min - 1){
                    compare = compare.substr(0, j+1);
                }
            }
        }
        return compare;
    }
};
```

```cpp
// 纵向扫描
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 0; j < count; ++j) {
                if(strs[j][i] != c || i == strs[j].size()) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
```
