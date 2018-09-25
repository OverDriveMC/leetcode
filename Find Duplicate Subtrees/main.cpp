/**
给定一个二叉树,返回所有重复的子树,重复子树返回任意一个root即可
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> map;
        vector<TreeNode*>res;
        serialize(root, map);
        for(auto iter= map.begin(); iter!=map.end();++iter){
            if(iter->second.size()>1){
                res.push_back(iter->second[0]);
            }
        }
        return res;
    }
    string serialize(TreeNode* root, unordered_map<string,vector<TreeNode*>>&map){
        if(root==nullptr){
            return "";
        }
		/**
		这里注意需要加()不然例如：
		[0,0,0,0,null,null,0,null,null,null,0]
		会出现00的情况,但是子树结构并不一样
		*/
        string s= "("+ serialize(root->left,map) + to_string(root->val) + serialize(root->right,map)+")";
        map[s].push_back(root);
        return s;
    }
    
    
};