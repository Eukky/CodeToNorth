// 21. Merge Two Sorted Lists
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result, *p;
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }else if(l1 == NULL && l2 != NULL){
            return l2;
        }else if(l1 != NULL && l2 == NULL){
            return l1;
        }
        if(l1 -> val <= l2 -> val){
            result = l1;
            l1 = l1 -> next;
        }else{
            result = l2;
            l2 = l2 -> next;
        }
        p = result;
        while(l1 && l2){
            if(l1 -> val <= l2 -> val){
                p -> next = l1;
                p = p -> next;
                l1 = l1 -> next;
            }else{
                p -> next = l2;
                p = p -> next;
                l2 = l2 -> next;
            }
        }
        if(l1){
            p -> next = l1;
        }
        if(l2){
            p -> next = l2;
        }
        return result;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        if(l1 -> val < l2 -> val){
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }else{
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }
};