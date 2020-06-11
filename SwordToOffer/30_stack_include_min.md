# 30. 定义栈的数据结构

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的`min`函数（时间复杂度应为`O(1)`）。

## 题解

使用两个`stack`来存储元素，一个专门用于存放`min`值。  
`push`操作：如果新元素小于`min`的栈顶元素，则分别在两个栈中压入新元素。  
`pop`操作：如果两个`stack`栈顶元素相等，则同时推出两个栈的栈顶元素。  

### C++

```cpp
class Solution {
public:
    stack<int> s;
    stack<int> mins;
    void push(int value) {
        s.push(value);
        if(mins.empty()){
            mins.push(value);
        }else if(value <= mins.top()){
            mins.push(value);
        }
    }
    void pop() {
        if(s.top() == mins.top()){
            mins.pop();
        }
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return mins.top();
    }
};
```
