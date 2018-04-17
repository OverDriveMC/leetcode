/*
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> >res;
        search(root,res,expectNumber);
        return res;
    }
    void search(TreeNode*root, vector<vector<int>>&res, int val){
        if(root==NULL){
            return ;
        }
        vector<int>cur;
		//搜索以当前结点为起始结点(包含)是否可以
        search(root,res,val,cur);
		//搜索以左右节点为起始结点(不一定包含)是否可以
        search(root->left,res,val);
        search(root->right,res,val);
    }
	//这一个search为寻找包含root这个节点的到叶子结点的路径值为val
    void search(TreeNode*root, vector<vector<int>>&res, int val, vector<int>&cur){
        if(root==NULL){
            return ;
        }
        cur.push_back(root->val);
        val-=root->val;
        if(val==0 && root->left==NULL && root->right==NULL){
            res.push_back(cur);
			//每次记得弹出添加的元素
            cur.pop_back();
            return ;
        }
		//减掉当前节点值,再往下分别搜索左子树,右子树
        search(root->left,res, val,cur );
        search(root->right,res, val,cur );
		//每次记得弹出添加的元素
        cur.pop_back();
    }
};