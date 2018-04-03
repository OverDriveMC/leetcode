/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/**
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*>q;
        if(root==NULL){
            return res;
        }
        q.push(root);
        while(!q.empty()){
			///每次队列里面都存储一层的
            int cnt=q.size();
            for(int i=0;i<cnt;i++){
                TreeNode* tmp=q.front();
                res.push_back(tmp->val);
                q.pop();
                if(tmp->left!=NULL){
                    q.push(tmp->left);
                }
                if(tmp->right!=NULL){
                    q.push(tmp->right);
                }
            }
            
        }
        return res;
    }
};