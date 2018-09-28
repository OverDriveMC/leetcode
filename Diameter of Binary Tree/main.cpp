/**
计算树直径
Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
*/
class Solution {
public:
    int maxn=0;
    int diameterOfBinaryTree(TreeNode* root) {
        getWidth(root);
        return maxn;
    }
    int getWidth(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        int left=getWidth(root->left);
        int right=getWidth(root->right);
		//最长为左右相加
        maxn=max(maxn, left+right);
        return max(left,right)+1;
    }
};