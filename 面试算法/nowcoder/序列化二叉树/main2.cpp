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
    char* Serialize(TreeNode *root) {
        if(root==NULL){
            return NULL;
        }
        ostringstream os;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cnt=q.size();
            for(int i=0;i<cnt;i++){
                TreeNode *tmp=q.front();
                q.pop();
                if(tmp==NULL){
                    os<<"#,";
                }else{
                    os<<tmp->val<<",";
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
        }
        char* res=new char[os.str().size()+1];
        strcpy(res,os.str().c_str());
        res[os.str().size() ]='\0';
        return res;
    }
    TreeNode* Deserialize(char *str) {
        if(str==NULL){
            return NULL;
        }
        int number=1;
        queue<TreeNode*>q;
        int index=0;
        int val=0;
        while(str[index]!='\0' && str[index]!=','){
            val=val*10+(str[index]-'0');
            index++;
        }
        index++;
        TreeNode*root=new TreeNode(val);
        q.push(root);
        while(!q.empty()){
            number=q.size();
            //cout<<"number:"<<number<<endl;
            TreeNode*parent=NULL;
			/**
			一共会有number*2个子节点加进来
			因为队列里有number个结点需要找孩子节点
			*/
            for(int i=0;i<number*2;i++){
				/**
				* 每找到两个孩子节点的时候,开始找下一个父节点的孩子
				*/
                if(i%2==0){
                    parent=q.front();
                    q.pop();
                }
				///为#的时候说明孩子节点为空
                if(str[index]=='#'){
                    if(i%2==0) parent->left=NULL;
                    else parent->right=NULL;
                    index+=2;
                }else{
					//计算数
                    int val=0;
                    while(str[index]!='\0' && str[index]!=','){
                        val=val*10+(str[index]-'0' );
                        index++;
                    }
                    index++;
                    //cout<<val<<"   ";
                    TreeNode*tmp=new TreeNode(val);
                    if(i%2==0) parent->left=tmp;
                    else parent->right=tmp;
                    q.push(tmp);
                }
            }
            //cout<<endl;
        }
        return root;
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
    return 0;
}
