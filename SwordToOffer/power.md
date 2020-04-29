# 数值的整数次方

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。  
保证base和exponent不同时为0

## 题解

判断幂的最后以为是否为1，如果为1，则将基数进行平方处理，如果不为1，则将计算计算结果乘以基数，每一次循环都将幂向右移一位。

```cpp
class Solution {
public:
    double Power(double base, int exponent) {
        int exp = abs(exponent);
        double res = 1;
        while(exp){
            if(exp & 1 == 1){
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return exponent > 0 ? res : 1 / res;
    }
};
```
