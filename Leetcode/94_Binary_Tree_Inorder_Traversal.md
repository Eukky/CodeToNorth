# 94. 中序遍历二叉树

## 题目

给定一个二叉树，返回它的中序遍历。  
示例:

```md
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
```

## 递归写法

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL) {
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};
```

## 树的遍历递归写法通用模版

```cpp
void traversal(TreeNode* root) {
    if(root != NULL) {
        //Todo --> 前序遍历
        traversal(root->left);
        //Todo --> 中序遍历
        traversal(root->right);
        //Todo --> 后序遍历
    }
    return;
}
```

- 时间复杂度$O(n)$。
- 空间复杂度最坏情况$O(n)$，平均情况$O(logn)$。

## 迭代写法

非递归写法需要借助栈来完成。  
非递归写法相对于递归写法更加难以理解，首先需要借助栈来遍历每个节点的左子树，在左子树遍历完成后，依次取栈中存放的节点，将节点的值存入vector中，再接着遍历右子树，以此来完成树的中序遍历。

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode* cur = root;
        while(cur != NULL || !s.empty()) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
```

- 时间复杂度$O(n)$。
- 空间复杂度$O(n)$。
