# 95. 不同的二叉搜索树 II

给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。  
示例:

```md
输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

## 递归解法

从序列`i...n`中取出第`i`个数字作为每一个树的根节点，则该节点左边的`i-1`个节点可以用于生成左子树，右边`n-i`个元素可以用于右子树。每一次循环都将生成的子树放入数组当中，接着遍历数组，为每一个子树添加左右节点，生成的新子树放入新的数组当中，返回该数组用于下一次迭代。

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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            return { };
        }
        return createTrees(1, n);
    }

    vector<TreeNode*> createTrees(int start, int end) {
        if(start > end) {
            return {nullptr};
        }
        vector<TreeNode*> res;
        for(int i = start; i <= end; ++i) {
            auto left = createTrees(start, i-1);
            auto right = createTrees(i+1, end);
            for(auto a : left) {
                for(auto b : right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
```
