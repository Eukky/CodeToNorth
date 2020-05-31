# 10.1 跳台阶

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

## 题解

每一次可以跳一级或者两级，因此到达每一级的跳法为：$f(n)=f(n-1)+f(n-2)$

### C++

- 循环解法

```cpp
class Solution {
public:
    int jumpFloor(int number) {
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
    int jumpFloor(int number) {
        if(number == 0) {
            return 1;
        }
        if(number == 1) {
            return 1;
        }
        return (jumpFloor(number - 1) + jumpFloor(number - 2));
    }
};
```

### Python

- 循环解法

```python
class Solution:
    def jumpFloor(self, n: int) -> int:
        a, b = 1,1
        for i in range(2,n+2):
            a, b = b, a+b
        return a%1000000007
```

- 递归解法

```python
class Solution:
    @lru_cache(None)
    def jumpFloor(self, n: int) -> int:
        if n == 0:
            return 1
        if n == 1:
            return 1
        return (self.numWays(n-1)+self.numWays(n-2))%1000000007
```
