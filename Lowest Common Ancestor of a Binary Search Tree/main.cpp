/**
有序二叉树中,查找最近公共父节点

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
Example 1:

Input: root, p = 2, q = 8
Output: 6 
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root, p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself 
             according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//直接找第一个  与两者做差符号相反的节点即可
        while( (root->val - p->val) *(root->val -q->val) >0 ){
            root= root->val >p->val ? root->left : root->right;
        }
        return root;
    }
};