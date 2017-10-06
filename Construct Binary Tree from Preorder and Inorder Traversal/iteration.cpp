#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

        if(preorder.size()==0)
            return NULL;

        stack<int> s;
        stack<TreeNode *> st;
        TreeNode *t,*r,*root;
        int i,j,f;

        f=i=j=0;
        s.push(preorder[i]);

        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;

        while(i<preorder.size()) {
            if(!st.empty() && st.top()->val==inorder[j]) {
                t = st.top();
                st.pop();
                s.pop();
                f = 1;
                j++;
                cout<<t->val<<endl;
            } else {
                if(f==0) {
                    cout<<"f==0  "<<preorder[i]<<"   "<<t->val<<endl;
                    s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);


                    i++;
                } else {
                    f = 0;
                    s.push(preorder[i]);
                    cout<<"f==1  "<<preorder[i]<<"   "<<t->val<<endl;
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }

        return root;
    }
};


/**
当前序遍历的结点等于 中序遍历的结点时,根节点前面的是左子树的结点,后面是右子树的结点
持续将前序遍历的结点入栈(并且成为前一个结点的左子树)直到栈顶元素和中序遍历结点一样
弹出栈顶元素,直到和中序遍历结点不一样(设置一个标志位)
重复1-2,关键步骤就是设置了标志位插在右子树,否则是左子树
*/
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return NULL;
        }

        stack<int>s;
        stack<TreeNode*>st;
        int i=0,j=0;
        bool flag=false;
        TreeNode * root=new TreeNode(preorder[i]);
        TreeNode*t=root;
        st.push(t);
        s.push(preorder[i]);
        i++;
        while(i<preorder.size()){
            while( !s.empty() && s.top()==inorder[j] ){
                ///当相等时,开始回溯,走到父节点,看是否还相等,一直往前回溯
                ///直到不相等时,说明下一个结点时右子树的
                t=st.top();
                ///置位
                flag=1;
                st.pop();
                s.pop();
                j++;
            }
            if(flag){
                ///假如置位,插在右子树上
                flag=0;
                t->right=new TreeNode(preorder[i]);
                t=t->right;
                s.push(preorder[i]);
                st.push(t);
                i++;
            }else{
                ///没有置位,插在左子树上
                s.push(preorder[i]);
                t->left=new TreeNode(preorder[i]);
                t=t->left;
                st.push(t);
                i++;
            }
        }
        return root;
    }
};


int main() {
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

}

