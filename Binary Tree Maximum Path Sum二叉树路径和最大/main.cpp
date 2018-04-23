/**
计算路径和最大的一条路径
Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
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
    int maxPathSum(TreeNode* root) {
        int maxn=-0x3fffffff;
        maxDepthSum(root, maxn);
        return maxn;
    }
	/**
	计算单条路径上最大和
	*/
    int maxDepthSum(TreeNode*root, int &maxn){
        if(root==NULL){
            return NULL;
        }
        int left=maxDepthSum(root->left,maxn);
        int right=maxDepthSum(root->right,maxn);
        int cur=root->val;
		/**
		假如left,right >0,则可以加进来
		否则必然没有root->val自身大
		*/
        if(left>0){
            cur+=left;
        }
        if(right>0){
            cur+=right;
        }
        maxn=max(maxn,cur);
		//注意,还要和0比较,可能两边都不加上才是最大的
        return max(0,max(left,right))+ root->val;
    }
};