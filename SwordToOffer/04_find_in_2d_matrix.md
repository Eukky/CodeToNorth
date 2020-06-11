# 04. 二维数组中的查找

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

## 题解

数组从左到右递增，从上到下递增，则从左下或者右上开始查找。

1. 若从左下开始查找，偏大则向右寻找，偏小则向上寻找。
2. 若从右上开始查找，偏大则向下寻找，偏小则向左寻找。

### C++

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i <= m - 1 && j >= 0){
            if(target > matrix[i][j]){
                i++;
            }else if(target < matrix[i][j]){
                j--;
            }else{
                return true;
            }
        }
        return false;
    }
};
```

### Python

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

### Rust

```rust
impl Solution {
    pub fn find_number_in2_d_array(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if matrix.len() == 0 || matrix[0].len() == 0 {
            return false;
        }
        let (m, n) = (matrix.len(), matrix[0].len());
        let mut i = 0;
        let mut j = n - 1;
        while i <= m - 1 && j >= 0 {
            if target > matrix[i][j] {
                i += 1;
            } else if target < matrix[i][j] {
                //j的类型为usize,需判断j是否大于等于1，否则会造成溢出
                if j > 0 {
                    j -= 1;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        }
        return false;
    }
}
```
