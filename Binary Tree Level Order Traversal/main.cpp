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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(root==NULL){
            return res;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>vec;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                
            }
            res.push_back(vec);
            
            
        }
        return res;    
    }
};