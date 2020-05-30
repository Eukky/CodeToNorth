# 两个栈实现队列

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

## 题解

设置两个栈 `stack1` 和 `stack2`。`stack1` 负责存储进入队列的数据，将`stack1`中的数据取出再压入`stack2`，此时`stack2`的栈顶元素相当于队列的头元素。

### C++版本

```cpp
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

### Python版本
```python
class CQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def appendTail(self, value: int) -> None:
        return self.stack1.append(value)

    def deleteHead(self) -> int:
        if self.stack1 == [] and self.stack2 == []:
            return -1
        elif self.stack1 != [] and self.stack2 == []:
            while self.stack1 != []:
                self.stack2.append(self.stack1.pop())
            return self.stack2.pop()
        elif self.stack2 != []:
            return self.stack2.pop()



# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```