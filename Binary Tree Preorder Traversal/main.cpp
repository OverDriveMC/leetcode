#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*

使用队列不行,这样打出来的是层次遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>vec;
        if(root==NULL){
            return vec;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*cur=q.front();
            vec.push_back(cur->val);
            //cout<<cur->val<<endl;
            q.pop();
            if(cur->left!=NULL){
                q.push(cur->left);
            }
            if(cur->right!=NULL){
                q.push(cur->right);
            }

        }
        return vec;
    }
};
*/
/**
先根,在左,在右

*/
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>vec;
        if(root==NULL){
            return vec;
        }
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode*cur=s.top();
            vec.push_back(cur->val);
            s.pop();
            ///栈 先进 后出,所以先添加右子树,再添加左子树
            if(cur->right!=NULL){
                s.push(cur->right);
            }
			///左子树在这里进了栈,然后下次循环便会马上出栈,然后开始遍历
            if(cur->left!=NULL){
                s.push(cur->left);
            }

        }
        return vec;
    }
};



class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>vec;
        preorderTraversal(root,vec);
        return vec;
    }
    void preorderTraversal(TreeNode* root,vector<int>&vec){
        if(root==NULL){
            return ;
        }
        vec.push_back(root->val);
        preorderTraversal(root->left,vec);
        preorderTraversal(root->right,vec);
    }
};


int main()
{
    TreeNode * root=new TreeNode(5);
    TreeNode * left1=new TreeNode(4);
    root->left=left1;
    TreeNode * right2=new TreeNode(3);
    root->right=right2;
    TreeNode * left11=new TreeNode(2);
    left1->left=left11;
    TreeNode * left12=new TreeNode(1);
    left1->right=left12;
    TreeNode * right21=new TreeNode(6);
    right2->left=right21;

    Solution s;
    vector<int>vec=s.preorderTraversal(root);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
