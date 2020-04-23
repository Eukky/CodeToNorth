# 1.两数之和

## 题目

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。  
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。  
示例:  

```md
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

## 暴力搜索

直接进行两轮迭代来寻找合适的解。

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            int tmp = target - nums[i];
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[j] == tmp){
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};
```

- 时间复杂度$O(n^2)$。
- 空间复杂度$O(1)$。

## 使用哈希表求解

使用一遍哈希，在第一次迭代的同时将数一个个放入map中，并在每一次循环中寻找已经存放在map中的数是否有匹配的值。

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            int num = target - nums[i];
            if(m.find(num) != m.end()) {
                res.push_back(m[num]);
                res.push_back(i);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
```

- 时间复杂度$O(n)$。
- 空间复杂度$O(n)$。
