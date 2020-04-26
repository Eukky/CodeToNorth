// 统计一个数字在排序数组中出现的次数。

class Solution {
    int search(vector<int> &data, double k){
        int m = 0;
        int n = data.size() - 1;
        while(m <= n){
            int mid = (m + n) / 2;
            if(data[mid] > k){
                n = mid - 1;
            }else if(data[mid] < k){
                m = mid + 1;
            }
            
        }
        return m;
    }
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0){
            return 0;
        }
        return search(data, k + 0.5) - search(data, k - 0.5);
    }
};