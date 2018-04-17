/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        return find(pRoot,k);        
    }
	/**
	中序遍历一遍,找第k大
	注意k传递引用,这样就不需要在额外添加个全局变量index记录大小位置了
	返回NULL,说明没有找到,否则便是结果
	*/
    TreeNode* find(TreeNode*root, int &k){
        if(root==NULL){
            return root;
        }
		//中序遍历,先访问左边
        TreeNode* left=find(root->left,k);
        if(left==NULL){
			//左边没找到,判断当前结点是不是第1个
			//k--之后判断是否第0个,
            k--;
            if(k==0){
                return root;
            }
			//判断完当前结点,在访问右边,中序遍历的正常顺序,只是将全局的index,变成了传递引用的k
            return find(root->right,k);
        }else{
            return left;
        }
    }
    
};