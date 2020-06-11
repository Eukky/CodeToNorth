# 35. 复杂链表的复制

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

## 题解

1. 起始链表`N1->N2->N3->...`
2. 构造一个相同的节点插入链表当中，形成链表`N1->N1->N2->N2->N3->N3->...`
3. 调整每个节点的`random`指针
4. 在新链表中提取出新构造的链表，形成新的链表。

### C++

```cpp
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL){
            return NULL;
        }
        RandomListNode* current = pHead;
        while(current){
            RandomListNode* node = new RandomListNode(current -> label);
            node -> next = current -> next;
            current -> next = node;
            current = node -> next;
        }
        current = pHead;
        while(current){
            if(current -> random){
                current -> next -> random = current -> random -> next;
            }
            current = current -> next -> next;
        }
        current = pHead;
        RandomListNode *clone = pHead -> next;
        RandomListNode *tmp;
        while(current -> next){
            tmp = current -> next;
            current -> next = tmp -> next;
            current = tmp;
        }
        return clone;
    }
};
```
