#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
///先左后根在右
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>vec;
        inorderTraversal(root,vec);
        return vec;
    }
    void inorderTraversal(TreeNode* root,vector<int>&vec){
        if(root!=NULL){
            inorderTraversal(root->left,vec);
            vec.push_back(root->val);
            inorderTraversal(root->right,vec);
        }

    }
};

/**
压入顺序:右子树,根,左子树
只有当左子树访问完后,才能访问根节点
对于任一结点P：
    若其左孩子不为空,则将P入栈,并将P的左孩子置位当前的,然后对当前结点P在进行相同的处理
    若其左孩子为空,则取栈顶元素并进行出栈操作,访问该栈顶结点,然后将当前的P置为栈顶结点的右孩子
    直到P为NULL,并且栈为空则遍历结束
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>vec;
        stack<TreeNode*>s;
        TreeNode* node=root;
        while(!s.empty() || node!=NULL ){
            if(node!=NULL){
                s.push(node);
                node=node->left;
            }else{
                ///左子树为空,访问根节点,根节点访问完,访问右子树
                node=s.top();
                s.pop();
                vec.push_back(node->val);
                node=node->right;
            }
        }

        return vec;
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
    vector<int>vec=s.inorderTraversal(root);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
