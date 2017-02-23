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
    //第一个遇到的节点出现之前没有遍历完的节点为1,正在遍历的节点为2,遍历完的节点为3.
    map<TreeNode*,int>vis;
    int flag=0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vis.clear();
        flag=0;
        if(p==root || q==root){
            return root;
        }
        if(p==q){
            return p;
        }
        return dfs(root,p,q);
    }
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root!=NULL){
            ///flag标记当前找到了几个节点
            if(flag==0){
                ///为0时,说明还没有找到一个节点,所以涂色为1
                vis[root]=1;
            }else{
                ///否则至少找到了1个节点,判断当前节点是否是另一个,假如是，返回即可
                if(root==p || root==q){
                    flag=2;
                    return NULL;
                }
                vis[root]=2;
            }
            if(root==p || root==q){
                flag=1;
            }

            TreeNode * res=dfs(root->left,p,q);
            /**
            *假如已经找到了,返回结果
            */
            if(res!=NULL){
                return res;
            }
            /**
            *flag=2的时候便说明已经找到了结果,只需要找到vis[root]=1的节点为结果
            */
            if(flag==2){
                if(vis[root]==1){
                    return root;
                }
                return NULL;
            }
            res=dfs(root->right,p,q);
            if(res!=NULL){
                return res;
            }
            if(flag==2){
                if(vis[root]==1){
                    return root;
                }
                return NULL;
            }
            vis[root]=3;
        }
        return NULL;
    }
};

int main(){
    TreeNode *root=new TreeNode(3);
    TreeNode *t1=new TreeNode(5);
    TreeNode *t2=new TreeNode(1);
    TreeNode *t11=new TreeNode(6);
    TreeNode *t12=new TreeNode(2);
    TreeNode *t121=new TreeNode(7);
    TreeNode *t122=new TreeNode(4);
    TreeNode *t21=new TreeNode(0);
    TreeNode *t22=new TreeNode(8);
    root->left=t1;
    root->right=t2;
    t2->left=t21;
    t2->right=t22;
    t12->left=t121;
    t12->right=t122;
    t1->left=t11;
    t1->right=t12;

    Solution s;
    TreeNode *res=s.lowestCommonAncestor(root,t1,t2);
    if(res!=NULL){
        cout<<res->val<<endl;
    }
    res=s.lowestCommonAncestor(root,t11,t21);
    cout<<s.vis[root]<<endl;
    if(res!=NULL){
        cout<<res->val<<endl;
    }
    return 0;
}

