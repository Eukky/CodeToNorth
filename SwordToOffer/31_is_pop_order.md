# 31. 栈的压入、弹出序列

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。  
假设压入栈的所有数字均不相等。例如序列`1,2,3,4,5`是某栈的压入顺序，序列`4,5,3,2,1`是该压栈序列对应的一个弹出序列，但`4,3,5,1,2`就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

## 题解

使用一个栈来模拟压入和弹出。每次压入之后判断栈顶元素是否能够为当前弹出序列的元素，如果不是继续压入，如果是则将该元素弹出，遍历到下一个弹出元素。

### C++

```cpp
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0){
            return false;
        }
        stack<int> s;
        for(int i = 0, j = 0; i < pushV.size();){
            s.push(pushV[i++]);
            while(j < popV.size() && s.top() == popV[j]){
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};
```
