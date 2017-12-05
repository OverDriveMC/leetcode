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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /**
         * 返回,可能两种情况,一种是一个是另一个的父节点,那么left,right一边会有一个NULL
         * 另一种情况是,left right都不为NULL,即left,right子树各有一个节点
         */
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        /**
         * 假如left!=NULL,right!=NULL  =>说明是根为LCA
         * 假如left==NULL,right!=NULL  =>说明right为LCA
         * 假如left!=NULL,right==NULL =>说明left为LCA
         */
        return !left ? right : !right ? left : root;
    }
};
