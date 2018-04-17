#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL || k<=0){
            return NULL;
        }
        stack<TreeNode*>s;
        TreeNode*node=pRoot;
		//一开始不push,判断两个条件
        while(node || !s.empty()){
            /**
			每次push当前node值进入栈
			这样可以保证栈首的值永远不是NULL
			当node->right==NULL的时候,便可以正常取栈中的下一个元素,(每次node的位置都是没有访问过得子树的右边的位置)
			否则每次添加left,会重新添加一遍
			*/
			while(node){
                s.push(node);
                node=node->left;
            }
            node=s.top();
            s.pop();
            k--;
            if(k==0){
                return node;
            }
            node=node->right;
        }
        return NULL;
    }
};

int main(){
    TreeNode* first=new TreeNode(8);
    TreeNode* second=new TreeNode(6);
    TreeNode* third=new TreeNode(10);
    first->left=second;
    first->right=third;
    TreeNode* forth=new TreeNode(5);
    TreeNode* fifth=new TreeNode(7);
    second->left=forth;
    second->right=fifth;
    TreeNode* sixth=new TreeNode(9);
    TreeNode* seventh=new TreeNode(11);
    third->left=sixth;
    third->right=seventh;
    Solution s;
    cout<<s.KthNode(first,3)->val<<endl;
    return 0;
}
