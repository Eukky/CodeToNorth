# 18. 删除链表的节点

给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。

> 示例 1:
>
> 输入: head = [4,5,1,9], val = 5
>
> 输出: [4,1,9]
>
> 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
>
> 示例 2:
>
> 输入: head = [4,5,1,9], val = 1
>
> 输出: [4,5,9]
>
> 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
>
> 说明：
>
> 题目保证链表中节点的值互不相同, 若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点

## 题解

删除节点之后，将前后的节点重新相连即可。

### Python

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if head == None:
            return None
        if head.val == val:
            return head.next
        if head.next == None and head.val != val:
            return head
        p1, p2 = head, head.next
        while p2.val != val and p2.next != None:
            p1, p2 = p1.next, p2.next
        if p2.val == val:
            p1.next = p2.next
            p2.next = None
        return head
```
