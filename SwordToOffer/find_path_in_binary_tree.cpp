// 结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)

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
    void dfs(TreeNode* root, vector<vector<int>> &res, vector<int> &trace, int sum){
        trace.push_back(root -> val);
        if(!root -> left && !root -> right){
            if(sum == root -> val){
                res.push_back(trace);
            }
        }
        if(root -> left){
            dfs(root -> left, res, trace, sum - root -> val);
        }
        if(root -> right){
            dfs(root -> right, res, trace, sum - root -> val);
        }
        trace.pop_back();
        return;
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> trace;
        if(root){
            dfs(root, res, trace, expectNumber);
        }
        return res;
    }
};