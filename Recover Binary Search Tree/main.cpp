/**
中序遍历元素为：
  6 3 4 5 2
每次和他后面的一个元素比较,发现6是第一个元素需要交换因为6>3
2是第二个元素要去交换,因为2<5
在中序遍历中,每次比较当前结点和前一个结点

*/


class Solution{
	
public:
	TreeNode *first=NULL;
	TreeNode *second=NULL;
	TreeNode *pre=new TreeNode(INT_MIN);
	
	void recoverTree(TreeNode* root){
		reverse(root);
		swap(first->val,second->val);
        /*
		这里交换指针是不行的,画一下就知道了
		因为只是改了first,second的指向,并没有改变树上的指向
        TreeNode *temp=first;
		first=second;
		second=temp;
        */
	}
	void reverse(TreeNode*root){
		if(!root){
			return ;
		}
		reverse(root->left);
		if(first==NULL && pre->val  >  root->val){
			first=pre;
		}
		/**
		*  这样写是不行的,因为最后一个错误情况是second,
		*例如  2 3 1 
		找到第一个是3之后,注意这个时候first就不是NULL了,接着往下走,这时候second为NULL,然后这个时候pre还是3，root为2
		这时会认为second为2,这样是不对的
		*/
		// if (first && !second && pre->val > root->val) second = root; 
		
		if(first!=NULL && pre->val > root->val){
			second=root;
		}
		
		pre=root;
		
		reverse(root->right);
	}
	
};