/**
计算二叉树所有的左叶子节点的和
    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
		/**
			假如左孩子节点不为空，并且左孩子为叶子结点，那么说明是左叶子结点
			计算加和，同时计算右子树的左叶子节点的和
		*/
        if(root->left!=NULL  && root->left->left==NULL  && root->left->right==NULL){
            return root->left->val + sumOfLeftLeaves(root->right);
        }else{
			//分别找左子树的左叶子节点和与右子树的左叶子节点和
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
    }
};