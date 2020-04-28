# 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。  
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。  
例如数组`{3,4,5,1,2}`为`{1,2,3,4,5}`的一个旋转，该数组的最小值为`1`。  
NOTE：给出的所有元素都大于`0`，若数组大小为`0`，请返回`0`。  

## 题解

使用二分查找，分析如下三种情况：

- `mid`大于`right`，则最小数字在`mid`右边，最高优先级，例如`{3,4,5,1,2}`。
- `mid`小于等于`right`的情况下，`mid`等于`left`，则最小数字在`mid`左边(包括`mid`)，使`right-1`进行顺序查找，优先级第二，例如`{2,1,2,2,2}`，`{2,2,2,1,2}`。
- `mid`小于等于`right`的情况下，`mid`不等于`left`，若`mid`小于`left`，则最小数字在`mid`左边(包括`mid`)，例如`{3,1,2,2,2}`。若`mid`大于`left`，则最小数字依旧在`mid`左边(包括`mid`)，例如`{1,2,3,4,5}`。

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
