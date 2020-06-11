# 从上往下打印二叉树

从上往下打印出二叉树的每个节点，同层节点从左至右打印。

## 题解

使用队列，在每一次遍历时都将队列头部节点的左孩子和右孩子依次放入队列，循环结束之后将队列头部元素推出，存入结果数组当中，以此来完成二叉树的从上往下打印。

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root == NULL){
            return res;
        }
        q.push(root);
        while(!q.empty()){
            res.push_back(q.front() -> val);
            if(q.front() -> left != NULL){
                q.push(q.front() -> left);
            }
            if(q.front() -> right != NULL){
                q.push(q.front() -> right);
            }
            q.pop();
        }
        return res;
    }
};
```
