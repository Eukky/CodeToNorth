// 输入一个链表，输出该链表中倒数第k个结点。

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