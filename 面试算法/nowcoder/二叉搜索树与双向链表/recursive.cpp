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
    TreeNode* prev=NULL;
    TreeNode *root=NULL;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        inOrderTraverse(pRootOfTree);
        return root;
    }
    void inOrderTraverse(TreeNode* node){
        if(node!=NULL){
			/**
			*直接递归写法,记录下root,prev即可
			*/
            inOrderTraverse(node->left);
            if(root==NULL){
                root=node;
            }
            if(prev==NULL){
                prev=node;
            }else{
                prev->right=node;
                node->left=prev;
                prev=node;
            }
            inOrderTraverse(node->right);
            
        }
    }
};