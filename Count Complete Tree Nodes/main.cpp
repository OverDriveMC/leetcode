//统计完全二叉树的节点数
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
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }        
        int hl=0,hr=0;
        TreeNode*left=root;
        while(left!=nullptr){
            hl++;
            left=left->left;
        }
        TreeNode*right=root;
        while(right!=nullptr){
            hr++;
            right=right->right;
        }
		/**
		如果左子树最长路径与右子树最长路径一样长,那么说明是满二叉树,直接计算节点数即可
		*/
        if(hl==hr){
            return (1<<hl)-1;
        }
		//否则,分别统计左右子树的节点数
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};