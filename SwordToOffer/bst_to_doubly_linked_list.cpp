// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

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