// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* head = new ListNode(0);
        head -> next = pHead;
        ListNode* pre = head;
        ListNode* last = head -> next;
        while(last != NULL){
            if(last -> next != NULL && last -> val == last -> next -> val){
                while(last -> next != NULL && last -> next -> val == last -> val){
                    last = last -> next;
                }
                pre -> next = last -> next;
                last = last -> next;
            }else{
                pre = pre -> next;
                last = last -> next;
            }
        }
        return head -> next;
    }
};