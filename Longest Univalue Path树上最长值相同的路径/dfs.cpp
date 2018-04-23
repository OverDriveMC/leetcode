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
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode*root,int &res){
        if(root==NULL){
            return 0;
        }
        int left=dfs(root->left, res);
        int right=dfs(root->right,res);
        if(root->left==NULL || root->left->val!=root->val ){
            left=0;
        }else{
            left++;
        }
        if(root->right==NULL || root->right->val != root->val){
            right=0;
        }else{
            right++;
        }
        res=max(res,left+right);
        return max(left,right);
    }
};