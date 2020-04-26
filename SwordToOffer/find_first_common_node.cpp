// 输入两个链表，找出它们的第一个公共结点。

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        int len1 = 0, len2 = 0, diff = 0;
        while(p1 != NULL){
            p1 = p1 -> next;
            len1++;
        }
        while(p2 != NULL){
            p2 = p2 -> next;
            len2++;
        }
        if(len1 > len2){
            diff = len1 - len2;
            p1 = pHead1;
            p2 = pHead2;
        }else{
            diff = len2 - len1;
            p1 = pHead2;
            p2 = pHead1;
        }
        for(int i = 0; i < diff; ++i){
            p1 = p1 -> next;
        }
        while(p1 != p2){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return p1;
    }
};