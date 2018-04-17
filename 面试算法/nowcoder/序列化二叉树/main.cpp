/**
请实现两个函数，分别用来序列化和反序列化二叉树
*/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
	/**
	采用前序遍历存储树,
	两个节点之间使用 , 分割(可能比10大因为)
	节点为NULL的使用# 表示, 左右孩子节点都为# 的表示为叶子结点
	*/
    char* Serialize(TreeNode *root) {
        if(root==NULL){
            return NULL;
        }
        stack<TreeNode*>s;
        s.push(root);
        ostringstream os;
        bool first=true;
        while(!s.empty()){
            TreeNode* tmp= s.top();
            s.pop();
            if(first){
                if(tmp!=NULL){
                    os<<tmp->val;
                }else{
                    os<<'#';
                    continue;
                }
                first=false;
            }else{
                if(tmp!=NULL){
                    os<<","<<tmp->val;
                }else{
                    os<<",#";
                    continue;
                }
            }
			/**
			*先加进来 在判空
			*不能先判空,再添加
			*/
            s.push(tmp->right);
            s.push(tmp->left);
        }
        ///os.str().c_str()返回的是const char*
        char * res=new char[os.str().size()+1];
        strcpy(res,os.str().c_str());
        return res;
    }
    TreeNode* Deserialize(char *str) {
        if(str==NULL){
            return NULL;
        }
        int index=0;
        return Deserialize(str,index);
    }
	/**
	注意index必须传递引用,这样就能保证构造完左子树,index下标便开始是右子树的开始,直接再去构造右子树
	*/
    TreeNode* Deserialize(char*str,int &index){
		//为\0或者#的时候代表结束
        if(str[index]=='\0' || str[index]=='#'){
            index+=2;
            return NULL;
        }
        int val=0;
		///读取每个节点的值
        while(str[index]!='\0' && str[index]!=','){
            val=val*10+(str[index]-'0');
            index++;
        }
        index++;
        TreeNode*root=new TreeNode(val);
        cout<<val<<"   ";
		//构造完左子树,开始构造右子树
        root->left=Deserialize(str,index);
        root->right=Deserialize(str,index);
        return root;
    }

    void postOrder(TreeNode*root){
        stack<TreeNode*>s;
        if(root==NULL){
            return;
        }
        s.push(root);
        s.push(root);
        while(!s.empty()){
            TreeNode*node=s.top();
            s.pop();
			///注意,这里要判断下s.empty(),最后一个节点的时候top没有值
            if(!s.empty() && node==s.top()){
				//先右在左
                if(node->right!=NULL){
                    s.push(node->right);
                    s.push(node->right);
                }
                if(node->left!=NULL){
                    s.push(node->left);
                    s.push(node->left);
                }
            }else{
                cout<<node->val<<endl;
            }
        }
    }
};



int main(){
    TreeNode* first=new TreeNode(15);
    TreeNode* second=new TreeNode(20);
    TreeNode* third=new TreeNode(30);
    first->left=second;
    first->right=third;
    TreeNode* forth=new TreeNode(45);
    TreeNode* fifth=new TreeNode(51);
    second->left=forth;
    second->right=fifth;
    TreeNode* sixth=new TreeNode(68);
    TreeNode* seventh=new TreeNode(79);
    third->left=sixth;
    third->right=seventh;
    Solution s;
    char* res=s.Serialize(first);
    cout<<res<<endl;
    TreeNode*root=s.Deserialize(res);
    cout<<endl;
    cout<<s.Serialize(root)<<endl;
    s.postOrder(root);
    return 0;
}
