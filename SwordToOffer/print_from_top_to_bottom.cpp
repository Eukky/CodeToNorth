// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
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