# 05. 替换空格

请实现一个函数，将一个字符串中的每个空格替换成`“%20”`。例如，当字符串为`We Are Happy`.则经过替换之后的字符串为`We%20Are%20Happy`。

## 题解

首先遍历字符串，统计其中包含的空格数，根据空格数来计算替换之后的字符串总长度。根据字符串当前总长度和替换后总长度，从后往前依次进行字符替换。

也可以直接再生成一个str，遍历s，若为空格，则在str后添加 `%20`， 否则添加s[i]。

### C++

```cpp
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int len = 0;
        int count = 0;
        int i = 0;
        while(str[i] != '\0'){
            len++;
            if(str[i] == ' '){
                count++;
            }
            i++;
        }
        int newlen = len + count * 2;
        if(newlen > length){
            return;
        }
        while(len != newlen){
            if(str[len] == ' '){
                str[newlen] = '0';
                newlen--;
                str[newlen] = '2';
                newlen--;
                str[newlen] = '%';
                newlen--;
                len--;
            }else{
                str[newlen] = str[len];
                newlen--;
                len--;
            }
        }
        return;
    }
};
```

### Python

```python
class Solution:
    def replaceSpace(self, s: str) -> str:
        if s == "":
            return ""
        res = ""
        for c in s:
            if c == " ":
                res = res + "%20"
            else:
                res = res + c
        return res
```
