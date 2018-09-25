class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }else if(root->left==nullptr){
			//这里特判一下root->left是否为nullptr,保证至少高度为2
            return 1;
        }
        int height=0;
        TreeNode*node=root;
        while(node->left!=nullptr){
            node=node->left;
            height++;
        }
		///因为是判断的left是否为null,所以实际高度应该为height+1
		///最左边的叶子结点与根节点有height条边相连
		///非叶子结点的数量为 (1<<height)-1
        return (1<<height)-1 + countNodes(root,height);
    }
    int countNodes(TreeNode*root, int height){
		///当height==1的时候,说明叶子结点到根节点只有1条边相连,
		//可以直接计算
        if(height==1){
            if(root->right!=nullptr){
                return 2;
            }else if(root->left!=nullptr){
                return 1;
            }else{
                return 0;
            }
        }
        int curHeight=0;
        TreeNode*node=root->left;
		//计算左子树的高度(curheight),  height是左子树叶子结点到根节点的边数,实际高度需要+1
        while(node){
            node=node->right;
            curHeight++;
        }
		//假如高度相同,说明左子树是完全二叉树,那么只要计算右子树的节点数即可
        if(curHeight==height){
            return (1<<height-1) + countNodes(root->right,height-1);
        }else{
			//高度不同,说明只要查找左子树的节点数就行
            return countNodes(root->left,height-1);
        }
    }
};