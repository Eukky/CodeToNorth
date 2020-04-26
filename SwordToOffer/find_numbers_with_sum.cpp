// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
// 输出描述:
// 对应每个测试案例，输出两个数，小的先输出。

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int size = array.size();
        int left = 0;
        int right = size - 1;
        while(right > left){
            int cur = array[left] + array[right];
            if(cur == sum){
                res.push_back(array[left]);
                res.push_back(array[right]);
                break;
            }else if(cur < sum){
                left++;
            }else{
                right--;
            }
        }
        return res;
        
    }
};