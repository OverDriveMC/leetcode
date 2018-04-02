/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

前序： 根左右  1 2 4 7 3 5 6 8
中序:  左根右  4 7 2 1 5 3 6 8
*/

struct TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
}

class Solution{
public:
	TreeNode*reConstructBinaryTree(vector<int>pre, vector<int>vin){
		return reConstructBinaryTree(pre,0,pre.size()-1,vin, 0, vin.size()-1);
	}
	///注意这里是vector
	TreeNode*reConstructBinaryTree(vector<int>pre, int pstart, int pend, vector<int>vin,int vstart,int vend){
		if(pend<pstart || vend<vstart){
			return NULL;
		}
		for(int i=vstart;i<=vend;i++){
			//在中序中,寻找根节点的位置
			if(pre[pstart]==vin[i] ){
				TreeNode * node=new TreeNode(pre[pstart]);
				///分别构造左右子树     (pstart+1)+ (i-1-vstart)   
				node->left=reConstructBinaryTree(pre, pstart+1, pstart+i-vstart  ,vin  ,vstart ,i-1 );
				node->right=reConstructBinaryTree(pre,pstart+i-vstart+1 ,pend  ,vin  ,i+1 ,vend );
				return node;
			}
		}
		return NULL;
	}
};