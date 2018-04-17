/**
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，
只能调整树中结点指针的指向。
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL){
            return NULL;
        }
        stack<TreeNode*>s;
        TreeNode*head=NULL;
        TreeNode*prev=NULL;
        TreeNode* node=pRootOfTree;   
/**
因为中序遍历的结果就是有序的,所以采用栈维护一个中序遍历的结果
*/
		
        while(node || !s.empty()){
            while(node){
                s.push(node);
                node=node->left;
            }
            node=s.top();
            s.pop();
			///记录下首指针
            if(head==NULL){
                head=node;
            }
			///记录下上一个结点
            if(prev==NULL){
                prev=node;
            }else{
                prev->right=node;
                node->left=prev;
                prev=prev->right;
            }
            node=node->right;
        }
        //prev->right=head;
        //head->left=prev;
        return head;
    }
};