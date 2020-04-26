//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        int n = array[0].size();
        int i = 0, j = n - 1;
        while(i <= m - 1 && j >= 0){
            if(target > array[i][j]){
                i++;
            }else if(target < array[i][j]){
                j--;
            }else{
                return true;
            }
        }
        return false;
    }
};