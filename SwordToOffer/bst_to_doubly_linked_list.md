# 二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

## 题解

使用树的中序遍历，根节点先和左子树的最右节点相连，再与右子树的最左节点相连。

```cpp
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};*/
class Solution {
    //last表示上一个节点，即每一次递归中需要和根节点相连的上一次递归的最后一个节点。
    TreeNode* last = NULL;
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL){
            return NULL;
        }
        TreeNode* head = Convert(pRootOfTree -> left);
        if(head == NULL){
            head = pRootOfTree;
        }
        pRootOfTree -> left = last;
        if(last != NULL){
            last -> right = pRootOfTree;
        }
        last = pRootOfTree;
        Convert(pRootOfTree -> right);
        return head;
    }
};
```
