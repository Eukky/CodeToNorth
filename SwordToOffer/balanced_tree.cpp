// 输入一棵二叉树，判断该二叉树是否是平衡二叉树。

class Solution {
    bool depth(TreeNode* pRoot, int &dep){
        if(pRoot == NULL){
            return true;
        }
        int left = 0;
        int right = 0;
        if(depth(pRoot -> left, left) && depth(pRoot -> right, right)){
            if(left - right > 1 || left - right < -1){
                return false;
            }
            dep = (left > right ? left : right) + 1;
            return true;
        }
        return false;
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return depth(pRoot, dep);
    }
};