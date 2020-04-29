# 链表中倒数第k个结点

输入一个链表，输出该链表中倒数第`k`个结点。

## 题解

定义两个指针，第一个指针先走`K`步，之后第二个指针跟着第一个指针一起走，直达第一个指针走到链表尾节点，第二个指针正好处于链表倒数第`K`个节点的位置。

```cpp
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k < 1){
            return NULL;
        }
        ListNode *pre = pListHead;
        ListNode *last = pListHead;
        while(k > 0){
            if(last == NULL){
                return NULL;
            }
            last = last -> next;
            k--;
        }
        while(last != NULL){
            last = last->next;
            pre = pre->next;
        }
        return pre;
    }
};
```