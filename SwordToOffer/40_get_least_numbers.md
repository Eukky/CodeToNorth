# 40. 最小的K个数

输入`n`个整数，找出其中最小的`K`个数。例如输入`4,5,1,6,2,7,3,8`这`8`个数字，则最小的`4`个数字是`1,2,3,4`。

## 题解

排序之后进行取数。

### C++

```cpp
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k > input.size()){
            return res;
        }
        sort(input.begin(), input.end());
        for(int i = 0; i < k; ++i){
            res.push_back(input[i]);
        }
        return res;
    }
};
```
