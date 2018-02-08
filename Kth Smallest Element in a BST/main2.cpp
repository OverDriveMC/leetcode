/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
因为中序遍历返回便是BST的有序序列
所以直接用栈模拟中序遍历,
直到k==1,返回即可
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        TreeNode*node=root;
        while(node!=NULL || !s.empty()){
            while(node){
                s.push(node);
                node=node->left;
            }
            TreeNode*t=s.top();
            s.pop();
            if(k--==1){
                return t->val;
            }
            node=t->right;
            
        }
        
        return NULL;
    }
};