// 输入一个链表，反转链表后，输出新链表的表头。

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
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