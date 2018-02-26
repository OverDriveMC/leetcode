/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL){
            return ;
        }
        queue<TreeLinkNode*>q;
        q.push(root);
        while(!q.empty()){
            int cnt=q.size();
            TreeLinkNode * pre=NULL;
			//使用队列模拟层序遍历
            for(int i=0;i<cnt;i++){
                TreeLinkNode* cur=q.front();
                q.pop();
                if(cur->left!=NULL){
                    q.push(cur->left);
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                }
                if(pre==NULL){
                    pre=cur;
                    continue;
                }
                pre->next=cur;
                pre=cur;
                
            }
            pre->next=NULL;
        }
    }
};