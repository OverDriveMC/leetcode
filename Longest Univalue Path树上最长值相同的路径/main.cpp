/**
在树上找一条路径最长的路径,在这条路上每个节点值都相同
              1
             / \
            4   5
           / \   \
          4   4   5
2
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
    int maxn=0;
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }        
		//这里val传什么都可以,因为返回值不重要,用不到根节点的返回值
        getLen(root,root->val);
        return maxn;
    }
	/**
	找和父节点值相同的路径长度(找的是单条路径方向)
	*/
    int getLen(TreeNode*root,int val){
        if(root==NULL){
            return 0;
        }
		/**
		在左右边分别寻找和父节点值相同的路径
		*/
        int left=getLen(root->left,root->val);
        int right=getLen(root->right,root->val);
		/**
		包含父节点的最长路径即为left+right
		看是否比当前的最长路径更长
		*/
        maxn=max(maxn,left+right);
		/**
		val是父节点的值,假如当前结点的val与父节点值相同,
		则返回left,right中大的那个+1
		*/
        if(val==root->val){
            return max(left,right)+1;
        }
		//否则返回0
        return 0;
        
    }
};
