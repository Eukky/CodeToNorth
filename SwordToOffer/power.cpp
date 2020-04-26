// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

// 保证base和exponent不同时为0

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