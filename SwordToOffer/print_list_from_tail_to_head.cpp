// 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

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