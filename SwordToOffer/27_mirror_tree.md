# 27. 二叉树的镜像

操作给定的二叉树，将其变换为源二叉树的镜像。  
输入描述:

```md
二叉树的镜像定义：
     源二叉树
        8
       /  \
      6   10
     / \  / \
    5   7 9 11
     镜像二叉树
        8
       /  \
      10   6
     / \  / \
    11  9 7  5
```

## 题解

交换每一个节点的左节点和右节点，依次递归。

### C++

```cpp
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL){
            return;
        }
        TreeNode* tmp = pRoot -> left;
        pRoot -> left = pRoot -> right;
        pRoot -> right = tmp;
        Mirror(pRoot -> left);
        Mirror(pRoot -> right);
    }
};
```
