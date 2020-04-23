# 2. 两数相加

给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。  
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。  
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。  
示例：

```md
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

## 算法

分别遍历两个链表，计算出每一次节点和`sum`以及进位`carry`，直到两个链表都遍历完成。  
如果最后一次计算`carry`为`1`，则额外再增加一个节点。

```cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* h = head;
        int sum = 0;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            if(carry == 1){
                sum++;
            }

            h -> next = new ListNode(sum % 10);
            h = h -> next;

            if(sum >= 10){
                carry = 1;
            }else{
                carry = 0;
            }
            sum = 0;
        }
        if(carry == 1){
            h -> next = new ListNode(1);
        }
        return head -> next;
    }
};
```

- 时间复杂度$O(max(m,n))$
- 空间复杂度$O(max(m,n))$
