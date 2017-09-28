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
    int kthSmallest(TreeNode* root, int k) {
        pair<bool,int>result=findKthSmallest(root,k);
		return result.first==true?result.second  : -1;
    }
	pair<bool,int>findKthSmallest(TreeNode*root,int k){
	    if(root==NULL){
            return make_pair(false,0);
	    }
	    //cout<<root->val<<"   "<<k<<endl;
/*
		if(root->left==NULL){
            if(k==1){
                return make_pair(true,root->val);
            }else{
                return make_pair(false,1);
            }
		}
*/
        ///先找左子树找第k大
		pair<bool,int>left=findKthSmallest(root->left,k);
		///假如返回true,说明在左子树中,second即为要找的
		if(left.first){
			return make_pair(true,left.second);
		}
		///假如为false,second代表左子树有多少个元素
		if(left.second==k-1){
			return make_pair(true,root->val);
		}
		//cout<<left.first<<"  "<<left.second<<"  "<<root->val<<endl;
		///左子树假如找不到,去右子树找
		pair<bool,int>right=findKthSmallest(root->right,k-1-left.second);
		///假如没有找到,返回该树的节点个数 左子树个数+右子树个数+1(自身)
		return right.first==true ? make_pair(true,right.second) : make_pair(false,left.second+right.second+1);
	}

};
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return find(root,k);
    }
    ///注意,这里k是引用传值
    int find(TreeNode*root, int &k){
        if(root==NULL){
            return -1;
        }
        int t=find(root->left,k);
        ///假如k==0说明是返回的元素,假如k==1说明是根元素,否则去右子树找
        ///每次find返回k都-1,因为每次都是少一个元素,从最小的元素减起
        return k==0 ? t : !--k ?root->val : find(root->right,k);
    }
};



int main(){
	TreeNode* root=new TreeNode(6);
	TreeNode* left1=new TreeNode(4);
	root->left=left1;
	TreeNode*right2=new TreeNode(8);
	root->right=right2;
	TreeNode* left11=new TreeNode(3);
	TreeNode* right12=new TreeNode(5);
	left1->left=left11;
	left1->right=right12;
	TreeNode* left111=new TreeNode(2);
	left11->left=left111;
	TreeNode*right22=new TreeNode(9);
	right2->right=right22;

	Solution s;
	for(int i=1;i<=7;i++){
        cout<<"i:"<<i<<" "<<s.kthSmallest(root,i)<<endl;
	}

	return 0;
}
