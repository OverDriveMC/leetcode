/**
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL){
            return pNode;
        }
        if(pNode->right==NULL){
			//一定要注意判断是否为NULL
            if(pNode->next!=NULL && pNode->next->val > pNode->val){
                return pNode->next;
            }else if(pNode->next!=NULL && pNode->next->next!=NULL && pNode->next->next->val > pNode->val){
                return pNode->next->next;
            }else{
                return NULL;
            }
        }else{
            pNode=pNode->right;
            while(pNode->left!=NULL){
                pNode=pNode->left;
            }
            return pNode;
        }
    }
};