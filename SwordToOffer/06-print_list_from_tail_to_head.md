# 06. 从尾到头打印链表

输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

## 题解

典型的“先进后出”，可利用栈实现。

### C++版本

```cpp
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        while(head != NULL){
            v.insert(v.begin(), head -> val);
            head = head -> next;
        }
        return v;
    }
};
```

### Python版本
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if head == None:
            return []
        res = []
        p = head
        while p != None:
            res.append(p.val)
            p = p.next
        return res[::-1]
```