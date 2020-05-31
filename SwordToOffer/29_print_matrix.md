# 29. 顺时针打印矩阵

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。  
例如，如果输入如下`4 X 4`矩阵：  
 `1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16`  
 则依次打印出数字  
 `1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10`。

## 题解

```md
1--2--3--4
         |
5--6--7  8
|     |  |
9  10-11 12
|        |
13-14-15-16

第一圈 1-2-3-4|8-12-16|15-14-13|9-5
第二圈 6-7|11|10
```

首先计算出打印矩阵所需要的圈数，每一圈都分成`4`部分一次进行打印，处理好边界即可。

### C++

```cpp
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int m = matrix[0].size();
        int n = matrix.size();
        int circle = ((m < n ? m : n) + 1) / 2;
        for(int i = 0; i < circle; ++i){
            for(int j = i; j < m - i; ++j){
                res.push_back(matrix[i][j]);
            }
            for(int j = i + 1; j < n - i; ++j){
                res.push_back(matrix[j][m - i - 1]);
            }
            for(int j = m - i - 2; (j >= i && (n - i - 1 != i)); --j){
                res.push_back(matrix[n - i - 1][j]);
            }
            for(int j = n - i - 2; (j >= i + 1 && (m - i - 1 != i)); --j){
                res.push_back(matrix[j][i]);
            }
        }
        return res;
    }
};
```
