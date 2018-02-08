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
因为BST的中序遍历是有序的
所以可以直接用栈模拟中序遍历,同时记录前一个元素
只要保证比前一个元素的val大即可
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode* pre=NULL;
        TreeNode*node=root;
        while(node!=NULL || !s.empty()){
			///每次只要左子树还有元素,就将当前元素入栈
            while(node!=NULL){
                s.push(node);
                node=node->left;
            }
			///出栈的便是最左边的结点
            TreeNode* t=s.top();
            s.pop();
            if(pre!=NULL && pre->val >= t->val){
                return false;
            }
            pre=t;
			///然后指向右子树
            node=t->right;
            
        }
        return true;
    }
};