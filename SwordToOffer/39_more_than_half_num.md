# 39. 数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。  
例如输入一个长度为`9`的数组`{1,2,3,2,2,2,5,4,2}`。由于数字`2`在数组中出现了`5`次，超过数组长度的一半，因此输出`2`。如果不存在则输出`0`。

## 题解

用preValue记录上一次访问的值，count表明当前值出现的次数，如果下一个值和当前值相同那么count++；如果不同count--，减到0的时候就要更换新的preValue值了，因为如果存在超过数组长度一半的值，那么最后preValue一定会是该值。

### C++

```cpp
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int num = numbers[0];
        int count = 1;
        for(int i = 0; i < numbers.size(); ++i){
            if(numbers[i] == num){
                count++;
            }else{
                count--;
            }
            if(count == 0){
                num = numbers[i];
                count = 1;
            }
        }
        count = 0;
        for(int i = 0; i < numbers.size(); ++i){
            if(numbers[i] == num){
                count++;
            }
            if(count > numbers.size() / 2){
                return num;
            }
        }
        return 0;
    }
};
```
