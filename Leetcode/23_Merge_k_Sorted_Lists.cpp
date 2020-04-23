// 23. Merge k Sorted Lists
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> q;
        ListNode* dummy = new ListNode(0); 
        ListNode* point = dummy;
        for(int i = 0; i < lists.size(); i++){
            ListNode* list = lists[i];
            while(!list == NULL){
                q.push(list -> val);
                list = list -> next;
            }
        }
        while(!q.empty()){
            point -> next = new ListNode(q.top());
            point = point -> next;
            q.pop();
        }
        return dummy -> next;
        
    }
};