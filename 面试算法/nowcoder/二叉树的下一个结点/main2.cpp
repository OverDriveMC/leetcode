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
		//如果有右子树,则找右子树的最左结点
        if(pNode->right!=NULL){
            pNode=pNode->right;
            while(pNode->left!=NULL){
                pNode=pNode->left;
            }
            return pNode;
        }
		//没右子树,找第一个当前结点是父节点左孩子的节点
        while(pNode->next!=NULL){
            if(pNode->next->left==pNode){
                return pNode->next;
            }
            pNode=pNode->next;
        }
		//退到了根节点仍没找到,返回null
        return NULL;
    }
};