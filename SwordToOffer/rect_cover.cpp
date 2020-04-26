// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

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