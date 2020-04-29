# 二进制中1的个数

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

## 题解

把一个整数减去1，再和原来的整数做相与运算，会把该整数二进制的最右边的1变成0。一个整数中有多少个1，就可以进行多少次上述的相与运算。

```cpp
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n){
             n = n & (n - 1);
             count++;
         }
         return count;
     }
};
```
