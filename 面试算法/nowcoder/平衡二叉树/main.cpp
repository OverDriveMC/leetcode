/**
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/
class Solution {
public:
	///定义个全局变量,用于剪枝
    bool balanced=true;
    bool IsBalanced_Solution(TreeNode* pRoot) {
        maxDepth(pRoot);
        return balanced;
    }
    int maxDepth(TreeNode* node){
        if(!balanced){
            return 0;
        }
        if(node==NULL){
            return 0;
        }
        int left=maxDepth(node->left);
        int right=maxDepth(node->right);
		///平衡二叉树左右节点深度不超过1
		///注意abs,取绝对值
        if( abs(right-left)>1 ){
            balanced=false;
        }
        return max(left,right)+1;
    }
};