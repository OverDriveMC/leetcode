#include<bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[0]);
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==preorder[0]){
                TreeNode*left=buildTree(preorder,1,i,inorder,0,i-1);
                TreeNode* right=buildTree(preorder,i+1,preorder.size()-1,inorder,i+1,inorder.size()-1);
                root->left=left;
                root->right=right;
               // cout<<"first:"<<root->val<<"  "<<left->val<<"  "<<right->val<<endl;
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder,int leftStart,int leftLast, vector<int>& inorder,
                        int rightStart,int rightLast){
        if(leftLast<leftStart){
            return NULL;
        }
        TreeNode * root=new TreeNode(preorder[leftStart]);
        for(int i=rightStart;i<=rightLast;i++){
            if(inorder[i]==preorder[leftStart]){
                TreeNode*left=buildTree(preorder,leftStart+1, leftStart+i-rightStart ,inorder,rightStart,i-1);
                TreeNode* right=buildTree(preorder,leftStart+i-rightStart+1 ,leftLast,inorder,i+1,rightLast);
                root->left=left;
                root->right=right;
/*
                cout<<"left:"<<leftStart<<"  "<<root->val<<"  "<<(left!=NULL ?left->val : NULL)<<"  "
                    <<(right!=NULL?right->val:NULL)<<endl;
*/
                break;
            }
        }
        return root;
    }

};



class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& preorder,int leftStart,int leftLast, vector<int>& inorder,
                        int rightStart,int rightLast){
        if(leftLast<leftStart){
            return NULL;
        }
        ///前序遍历第一个结点为根元素
        TreeNode * root=new TreeNode(preorder[leftStart]);
        for(int i=rightStart;i<=rightLast;i++){
            if(inorder[i]==preorder[leftStart]){
                ///找到中序遍历中的根元素
                ///分别构建左右子树
                root->left=buildTree(preorder,leftStart+1, leftStart+i-rightStart ,inorder,rightStart,i-1);
                root->right=buildTree(preorder,leftStart+i-rightStart+1 ,leftLast,inorder,i+1,rightLast);
                break;
            }
        }
        return root;
    }

};



void post(TreeNode*root){
    vector<int>vec;
    if(root==NULL){
        return ;
    }
    stack<TreeNode*>s;
    s.push(root);
    s.push(root);
    while(!s.empty()){
        TreeNode*node=s.top();
        s.pop();
        if(!s.empty() && node==s.top() ){
            if(node->right!=NULL){
                s.push(node->right);
                s.push(node->right);
            }
            if(node->left!=NULL){
                s.push(node->left);
                s.push(node->left);
            }
        }else{
            vec.push_back(node->val);
        }
    }
    cout<<endl<<"vec:";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    vector<int>pre;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(3);
    pre.push_back(4);
    pre.push_back(5);
    pre.push_back(6);
    pre.push_back(7);

    vector<int>in;
    in.push_back(3);
    in.push_back(2);
    in.push_back(4);
    in.push_back(1);
    in.push_back(6);
    in.push_back(5);
    in.push_back(7);

    Solution s;
    TreeNode*root= s.buildTree(pre,in);
    cout<<root->val<<"  "<<root->left->right->left<<"  "<<root->right->val  <<endl;
    post(root);

}
