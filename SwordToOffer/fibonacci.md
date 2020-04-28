# 斐波那契数列

大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项，从0开始，第0项为0。

## 题解

斐波那契数列：$f(n)=f(n-1)+f(n-2)$

- 循环解法

```cpp
class Solution {
public:
    int Fibonacci(int n) {
        int a = 0;
        int b = 1;
        while(n--){
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
    int Fibonacci(int n) {
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 1;
        }
        return (Fibonacci(n - 1) + Fibonacci(n - 2));
    }
};
```
