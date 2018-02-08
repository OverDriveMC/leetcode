/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
///采用 long long min   long long max
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL || (root->left == NULL && root->right==NULL) ){
            return true;
        }
        return isValidBST(root,LONG_LONG_MIN,LONG_LONG_MAX);
    }
    bool isValidBST(TreeNode*root, long long  minn,long long  maxn){
        if(root==NULL){
            return true;
        }
        if(root->val<=minn  || root->val >=maxn){
            return false;
        }
        return isValidBST(root->left, minn, root->val) && isValidBST(root->right, root->val, maxn);
        
    }
};