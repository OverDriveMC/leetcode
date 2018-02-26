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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(root==NULL){
            return res;
        }
        q.push(root);
        bool flag=false;
        while(!q.empty() ){
            int cnt=q.size();
			///初始化一个大小为cnt的vector
            vector<int>vec(cnt,0);
            for(int i=0;i<cnt;i++){
                TreeNode*node=q.front();
                q.pop();
                int index=i;
                if(flag){
                    index=cnt-i-1;
                }
				//计算好要插入的位置
                vec[index]=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            
                
            }
            flag=!flag;
            res.push_back(vec);
        }
        return res;
    }
};