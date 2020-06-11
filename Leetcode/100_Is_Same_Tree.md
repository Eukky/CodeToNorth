# 100. 相同的树

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

## 题解

- 递归法

  首先判断`p`和`q`是否为`None`，再判断其值是否相等，然后对他们的子节点做同样的操作即可。时间复杂度和空间复杂度均为`O(n)`。

- 迭代法

  用队列保存两棵树对应节点的信息，并设计一个辅助函数判断两个树的对应的节点是否相等。

### Python

```python
# 递归法
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        elif not p or not q:
            return False
        elif p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```

```python
# 迭代法
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def check(p, q):
            if not p and not q:
                return True
            elif not p or not q:
                return False
            elif p.val != q.val:
                return False
            else:
                return True

        Q = [(p,q)]
        while Q != []:
            elm = Q.pop(0)
            if not check(elm[0],elm[1]):
                return False

            if elm[0]:
                Q.append((elm[0].left, elm[1].left))
                Q.append((elm[0].right, elm[1].right))
        return True
```
