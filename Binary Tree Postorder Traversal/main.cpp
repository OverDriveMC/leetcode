#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
///左右根

class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>vec;
        postorderTraversal(root,vec);
        return vec;
    }
    void postorderTraversal(TreeNode* root,vector<int>&vec) {
        if(root!=NULL){
            postorderTraversal(root->left,vec);
            postorderTraversal(root->right,vec);
            vec.push_back(root->val);
        }
    }
};
/**
先压入根,然后是右子树,最后左子树
要求最后访问根节点,即访问根节点时必须访问完左子树和右子树,只需要保证访问某一节点时,
该节点的右子树已经被访问,否则需要将该节点重新压入栈。
第一种思路:
    对于任一结点,将其入栈,然后沿其左子树一直往下搜索,直到搜索到没有左孩子的结点,此时该节点出现在栈顶,
但是此时不能将其出栈并访问,因为其右孩子还未被访问,所以接下来按照相同的规则对其右子树进行相同的处理,
当访问完其右孩子时,该节点又出现在栈顶,此时可以将其出栈并访问。这样就保证了正确的访问顺序,可以看出
在这个过程中,每个节点都两次出现在栈顶,只有在第二次出现在栈顶时,才能访问它。因此需要多设置一个变量标识该
节点是否是第一次出现在栈顶(isFirst)。
第二种思路:
    要保证根节点在左孩子和右孩子访问之后才能访问,因此对于任一结点P,先将其入栈,如果P不存在左孩子和右孩子,
则可以直接访问它,或者P存在左孩子或者右孩子,但是其左孩子和右孩子已被访问过了,同样可以直接访问该节点,若非
以上两种情况,则将P的右孩子和左孩子依次入栈,这样就保证了每次取栈顶元素的时候,左孩子在右孩子前面被访问,
左孩子和右孩子都在根节点前面被访问。

*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>vec;
        if(root==NULL){
            return vec;
        }

        stack<TreeNode*>s;
        TreeNode* cur;  ///当前结点
        TreeNode* pre=NULL; ///前一次被访问的结点
        s.push(root);
        while(!s.empty()  ){
            cur=s.top();
            /**
            左右子树都为空可以直接打印

            或者左右子树有一个就是上一轮被访问过得(pre!=NULL的情况下才可以  pre==NULL的情况下,假如左子树为空会直接被打印,所以要排除)
            右子树比较好理解,访问过后,当前结点必然是可以访问的,
            pre==cur->left: 注意,如果有右子树的情况下,pre不可能等于cur->left,因为入栈的顺序是右子树,左子树
            pre==cur->left只可能在cur->right为NULL时才会出现
            */

            if( (cur->left==NULL && cur->right==NULL)
               || (!pre==NULL &&(pre==cur->left || pre==cur->right  ))
            ){
                s.pop();
                vec.push_back(cur->val);
                pre=cur;
            }else{
                ///右子树先入栈,然后左子树入栈
                if(cur->right!=NULL){
                    s.push(cur->right);
                }
                if(cur->left!=NULL){
                    s.push(cur->left);
                }
            }
        }

        return vec;
    }
};



int main()
{
    TreeNode * root=new TreeNode(5);
    TreeNode * left1=new TreeNode(4);
    root->left=left1;
    TreeNode * right2=new TreeNode(3);
    root->right=right2;
    TreeNode * left11=new TreeNode(2);
    left1->left=left11;
    TreeNode * left12=new TreeNode(1);
    left1->right=left12;
    TreeNode * right21=new TreeNode(6);
    right2->left=right21;

    Solution s;
    vector<int>vec=s.postorderTraversal(root);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
