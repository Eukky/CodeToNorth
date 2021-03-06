# 03. 数组中重复的数字

找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

> 示例 1：
>
> 输入：[2, 3, 1, 0, 2, 5, 3]
>
> 输出：2 或 3

## 题解

- 交换法：由于nums里的所有数字都在0~n-1，我们可构建一个哈希表辅助求解，然而这样做的空间复杂度为O(n)。为了实现O(1)的空间复杂度，可以考虑采用原地置换的方式，将原数组重新排序，使得位置 i 的数等于 i 。若`nums[nums[i]] == nums[i]`，则`nums[i]`重复了，反之交换二者的位置。

- 使用哈希表：将元素存入哈希表之后进行查询。

### C++

```cpp
//交换法
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] != i) {
                if(nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
```

### Python

```python
#交换法
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while nums[i] != i:
                if nums[nums[i]] == nums[i]:
                    return nums[i]
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
```

### Rust

```rust
//交换法
impl Solution {
    pub fn find_repeat_number(mut nums: Vec<i32>) -> i32 {
         for i in 0..nums.len() {
            let mut j = nums[i] as usize;
            while i != j {
                if nums[i] == nums[j] {
                    return nums[j];
                }
                nums.swap(i, j);
                j = nums[i] as usize;
            }
        }
        -1
    }
}
```

```rust
//使用哈希表
use std::collections::HashSet;
impl Solution {
    pub fn find_repeat_number(nums: Vec<i32>) -> i32 {
         let mut d = HashSet::new();
         for i in nums.iter(){
            if d.contains(i){
                return *i;
            }
            d.insert(*i);
        }
        -1
    }
}
```
