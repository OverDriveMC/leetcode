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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
    TreeNode* sortedArrayToBST(vector<int>&nums, int start, int last){
        if(last<start){
            return NULL;
        }
		//选中间的作为根节点
        int mid=start+(last-start)/2;
        TreeNode* root= new TreeNode(nums[mid]);
		//使用左边的构建左子树
        root->left= sortedArrayToBST(nums,start,mid-1);
		///右边的构建右子树
        root->right=sortedArrayToBST(nums,mid+1,last);
        return root;
    }
};