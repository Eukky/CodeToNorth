# 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。  
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。  
> 示例 1：
> 
> 输入：[3,4,5,1,2]
> 
> 输出：1

> 示例 2：
> 
> 输入：[2,2,2,0,1]
> 
> 输出：0

## 题解

使用二分查找，分析如下三种情况：

- 若`mid`大于`right`，则最小值在`mid`右边，例如`{3,4,5,1,2}`，此时将 `left` 更新为 `mid`
- 若`mid`小于`left`, 则最小值在`mid`左边，例如`5,1,2,3,4`，此时将 `right` 更新为 `mid`
- 否则，将`right`从右往左移动
### C++版本

```cpp
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size() - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(rotateArray[left] < rotateArray[mid]){
                left = mid + 1;
            }else if(rotateArray[left] == rotateArray[mid]){
                right--;
            }else{
                right = mid;
            }
        }
        return rotateArray[left];
    }
};
```

### Python版本

```python
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        if numbers == []:
            return None
        if len(numbers) == 1:
            return numbers[0]
        i = 0
        j = len(numbers) - 1
        if numbers[i] < numbers[j]:
                return numbers[i]
        while i + 1 != j:
            mid = (i + j)//2
            if numbers[mid] > numbers[j]:
                i = mid
            elif numbers[mid] < numbers[i]:
                j = mid
            else:
                j = j - 1
        return numbers[j]
```