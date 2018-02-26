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
    bool isSymmetric(TreeNode* left,TreeNode * right){
        if(left==NULL && right==NULL){
            return true;
        }
        if(left!=NULL && right!=NULL && left->val == right->val){
            return isSymmetric(left->right,right->left) && isSymmetric(left->left,right->right);
        }
        return false;
    } 
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return true;
        }
        if(root->left!=NULL && root->right!=NULL && root->left->val==root->right->val){
            return isSymmetric(root->left->left, root->right->right)  && isSymmetric(root->left->right,root->right->left);
        }
        return false;
    }
};