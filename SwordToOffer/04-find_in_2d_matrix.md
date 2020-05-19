# 04. 二维数组中的查找

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

## 题解

数组从左到右递增，从上到下递增，则从左下或者右上开始查找。

1. 若从左下开始查找，偏大则向右寻找，偏小则向上寻找。
2. 若从右上开始查找，偏大则向下寻找，偏小则向左寻找。 

### C++版本

```cpp
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
```

### Python版本

```python
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if matrix == []:
            return False
        
        n = len(matrix)
        m = len(matrix[0])

        i = 0
        j = m - 1
        while i < n and j >= 0:
            if matrix[i][j] == target:      
                return True                 # 找到
            elif matrix[i][j] > target:     # 若右上角的数大于target
                j = j - 1                   # 删除该列
            else:                           # 若右上角的数小于target
                i = i + 1                   # 删除该行
        return False                        
```
