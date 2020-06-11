# 树的子结构

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

## 题解

子函数`isSubtree()`用于判断形参中的两颗树是否相等，在主函数中调用子函数，判断二叉树`A`是否于`B`相等，`A`的左子树是否包含`B`，`A`的右子树是否包含`B`，满足条件之一即可完成判断。

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL){
            return false;
        }
        return isSubtree(pRoot1, pRoot2) ||
               HasSubtree(pRoot1 -> left, pRoot2) ||
               HasSubtree(pRoot1 -> right, pRoot2);
    }
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL){
            return true;
        }
        if(pRoot1 == NULL){
            return false;
        }
        if(pRoot1 -> val == pRoot2 -> val){
             return isSubtree(pRoot1 -> left, pRoot2 -> left) &&
                    isSubtree(pRoot1 -> right, pRoot2 -> right);
        }else{
            return false;
        }
    }
};
```
