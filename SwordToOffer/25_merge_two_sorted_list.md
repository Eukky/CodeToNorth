# 25. 合并两个排序的链表

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

## 题解

使用递归，每一次都可看作是当与去掉当前节点的两个链表之间的合并，递归完成合并。

### C++

```cpp
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL){
            return pHead2;
        }
        if(pHead2 == NULL){
            return pHead1;
        }
        if(pHead1 -> val <= pHead2 -> val){
            pHead1 -> next = Merge(pHead1 -> next, pHead2);
            return pHead1;
        }else{
            pHead2 -> next = Merge(pHead1, pHead2 -> next);
            return pHead2;
        }
    }
};
```
