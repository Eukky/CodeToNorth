// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* root = reConstruct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
        return root;
        
    }
    TreeNode* reConstruct(vector<int> pre, int startpre, int endpre, vector<int> vin, int startin, int endin){
        TreeNode* root = new TreeNode(pre[startpre]);
        if(startpre > endpre || startin > endin){
            return NULL;
        }
        for(int i = startin; i <= endin; ++i){
            if(vin[i] == pre[startpre]){
                root -> left = reConstruct(pre, startpre + 1, startpre + i - startin, vin, startin, i - 1);
                root -> right = reConstruct(pre, startpre + 1 + i - startin, endpre, vin, i + 1, endin);
                break;
            }
        }
        return root;
    }
};