/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL){
            return ;
        }
        //使用pre记录当期要建立Link的的上一层最左边的元素
        TreeLinkNode*pre=root;
        TreeLinkNode* cur=NULL;
        ///假如左子树不为空,说明可以继续下移
        while(pre->left!=NULL){
            ///使用上一层的元素来为下一层建立Link
            cur=pre;
            while(cur){
                ///左边的链接右边的
                cur->left->next=cur->right;
                if(cur->next){
                    ///假如后面还有元素,右边的链接下一颗子树的左子树节点
                    ///因为父节点都已经建好链了,所以可以直接通过Next到达下一棵树
                    cur->right->next=cur->next->left;
                }
                cur=cur->next;
            }
            pre=pre->left;
        }
    }
};