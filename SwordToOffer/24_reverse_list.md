# 24. 反转链表

输入一个链表，反转链表后，输出新链表的表头。

## 题解

在每次反转节点之前首先记录下一个要反转的节点`r`，反转之后依次移动`p`，`q`的指向。

```cpp
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *p, *q, *r;
        if(pHead == NULL || pHead -> next == NULL){
            return pHead;
        }
        p = pHead;
        q = pHead -> next;
        pHead -> next = NULL;
        while(q != NULL){
            r = q -> next;
            q -> next = p;
            p = q;
            q = r;
        }
        return p;
    }
};
```
