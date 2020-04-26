// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

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