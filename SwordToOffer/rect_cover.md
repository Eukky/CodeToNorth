# 矩形覆盖

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

## 题解

同样使用递推公式：$f(n)=f(n-1)+f(n-2)$

- 循环解法

```cpp
class Solution {
public:
    int rectCover(int number) {
        if(number == 0){
            return 0;
        }
        int a = 1;
        int b = 1;
        while(number--){
            b = a + b;
            a = b - a;
        }
        return a;
    }
};
```

- 递归解法

```cpp
class Solution {
public:
    int rectCover(int number) {
        if(number == 0) {
            return 0;
        }
        if(number == 1) {
            return 1;
        }
        if(number == 2) {
            return 2;
        }
        return (rectCover(number - 1) + rectCover(number - 2));
    }
};
```
