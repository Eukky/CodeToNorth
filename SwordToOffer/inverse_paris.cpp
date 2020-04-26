// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
// 输入描述:
// 题目保证输入的数组中没有的相同的数字
// 数据范围：
// 	对于%50的数据,size<=10^4
// 	对于%75的数据,size<=10^5
// 	对于%100的数据,size<=2*10^5
// 输入
// 1,2,3,4,5,6,7,0
// 输出
// 7

class Solution {
    int Merge(vector<int> &data, vector<int> &copy, int left, int right){
        if(left == right){
            return 0;
        }
        int mid = (left + right) / 2;
        int leftcount = Merge(data, copy, left, mid);
        int rightcount = Merge(data, copy, mid + 1, right);
        int count = 0;
        int i = mid;
        int j = right;
        int k = right;
        while(i >= left && j > mid ){
            if(data[i] > data[j]){
                count += j - mid;
                copy[k--] = data[i--];
                if(count>=1000000007)
                {
                    count%=1000000007;
                }
            }else{
                copy[k--] = data[j--];
            }
        }
        for(; i>= left; i--){
            copy[k--] = data[i];
        }
        for(; j > mid; j--){
            copy[k--] = data[j];
        }
        for(int n = left; n <= right; ++n){
            data[n] = copy[n];
        }
        return (leftcount + rightcount + count)%1000000007;
    }
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0){
            return 0;
        }
        vector<int> copy(data.size());
        int count = Merge(data, copy, 0, data.size() - 1);
        return count;
    }
};