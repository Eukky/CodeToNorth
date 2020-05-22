# 105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意: 你可以假设树中没有重复的元素。

本题与 ***剑指Offer面试题07*** 一样
## 题解
前序遍历：根节点，左子树，右子树
中序遍历：左子树，根节点，右子树
因此，前序遍历的第一个节点一定是**根节点**，其在中序遍历中对应的元素的左侧一定是根节点的左子树，右侧一定是根节点的右子树。根据中序遍历中得到的左子树的节点个数和右子树的节点个数，可将前序遍历中的左子树和右子树划分开，并得到左右子树的根节点，依次类推即可完成二叉树的构造。

在构造过程中，每次都需要找中序遍历中根节点所在位置，这样时间开销会比较大。为了降低时间复杂度，可用空间换时间，首先遍历一遍中序节点，将其对应的下标存入哈希表中，那么在之后的构建子树的过程中，即可以`O(1)`的复杂度快速定位中序遍历中根节点的位置。
### Python 版本

```python
# 未使用哈希表优化
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if preorder == [] or inorder == []:
            return None
        root = TreeNode(preorder[0])          # 前序遍历的第一个值为根节点
        for i in range(len(inorder)):
            if inorder[i] == root.val:
                inorder_left = inorder[0:i]
                inorder_right = inorder[i+1:]
                preorder_left = preorder[1:i+1]
                preorder_right = preorder[i+1:]

                root.left = self.buildTree(preorder_left, inorder_left)
                root.right = self.buildTree(preorder_right, inorder_right)
                return root
```

```python
# 使用哈希表优化
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def buildTreeHelper(preleft, preright, inleft, inright):
            if preleft > preright:
                return None
            root = TreeNode(preorder[preleft])

            i = hashmap[preorder[preleft]]
            root.left = buildTreeHelper(preleft+1, i+preleft-inleft, inleft, i-1)
            root.right = buildTreeHelper(i+preleft-inleft+1, preright, i+1, inright)
            return root

        if preorder == [] or inorder == []:
            return None
        n = len(preorder)
        hashmap = {val:i for i, val in enumerate(inorder)}
        return buildTreeHelper(0, n-1, 0, n-1)
```