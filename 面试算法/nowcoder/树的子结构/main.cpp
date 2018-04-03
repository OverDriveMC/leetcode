/**
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL || pRoot2==NULL){
            return false;
        }
		//判断包含当前节点出发,是否是子结构
		//同时判断是否左子树与右子树的子结构
        return isSubtree(pRoot1,pRoot2) || HasSubtree(pRoot1->left,pRoot2) ||HasSubtree(pRoot1->right,pRoot2);
    }
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		//pRoot2为NULL说明整个结构都包含在内
        if(pRoot2==NULL) return true;
		//pRoot1为NULL,说明不能包含所有子结构
        if(pRoot1==NULL) return false;
		//判断左子树与右子树
        if(pRoot1->val== pRoot2->val){
            return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
        }
        return false;
    }
};