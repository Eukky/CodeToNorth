// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2){
            return;
        }
        int index = 1;
        int tmp = 0;
        for(int i = 0; i < data.size(); ++i){
            tmp ^= data[i];
        }
        while((tmp & index) == 0){
            index <<= 1;
        }
        *num1 = tmp;
        *num2 = tmp;
        for(int i = 0; i < data.size(); ++i){
            if((index & data[i]) == 0){
                *num2 ^= data[i];
            }else{
                *num1 ^= data[i];
            }
        }
        return;
        
    }
};