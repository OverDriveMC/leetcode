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
    int maxPathSum(TreeNode* root) {
        //可能有负权值
        int maxVal=INT_MIN;
        maxPathDown(root,maxVal);
        return maxVal;
    }
    ///记录子树的最长路径
    int maxPathDown(TreeNode* root,int& maxVal){
        if(root==NULL){
            return 0;
        }
        int left=max(0,maxPathDown(root->left,maxVal) );
        int right=max(0, maxPathDown(root->right,maxVal));
        /**
        *树直径为: 左子树的最长路径 +  右子树的最长路径  +  当前节点的权值
        * 每次计算完毕更新
        */
        maxVal=max(maxVal, left+right+root->val);
        ///返回的是单个子树的最长路径(左子树 Or 右子树 长的那个 + 自身的权值)
        return max(left,right)+root->val;
        
    }
};