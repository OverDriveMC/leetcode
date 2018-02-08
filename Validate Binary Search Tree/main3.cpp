/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode*pre=NULL;
        return  isValidBST(root,pre);
    }
    ///这里必须要传引用,因为可能是遍历回来之后才知道pre指向的结点位置
    ///并非是确定pre的位置再去找下一个(因为访问左子树的时候实际也是在找pre的位置)
    bool isValidBST(TreeNode*root, TreeNode*& pre){
        if(root==NULL){
            return true;
        }
        if(!isValidBST(root->left,pre)){
            return false;
        }
/*
        前面一个不一定是root->left
        pre因为传递的是引用,会在递归中被修改
        
        if(root->left!=NULL){
            pre=root->left;
        }
*/
        if(pre!=NULL && pre->val >= root->val){
            return false;
        }
        pre=root;
        return isValidBST(root->right,pre);
    }
};