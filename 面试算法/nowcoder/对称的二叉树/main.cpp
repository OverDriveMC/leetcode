/*
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL){
            return true;
        }
		//判断左右子树是否相同
        return isSymmetrical(pRoot->left,pRoot->right);
    }
    bool isSymmetrical(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2==NULL){
            return true;
        }
        if(node1==NULL || node2==NULL){
            return false;
        }
        if(node1->val == node2->val){
			//分别判断第一棵树的左子树与第二颗树的右子树
			///第一棵树的右子树与第二颗树的左子树 是否相同
            return isSymmetrical(node1->left, node2->right) && isSymmetrical(node1->right, node2->left);
        }
        return false;
    }
};