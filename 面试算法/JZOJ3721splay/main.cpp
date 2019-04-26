/*
https://blog.csdn.net/liyizhixl/article/details/65641346
题目描述：
家乡中共有n个石桥等待修理，对于第i个石桥，我们定义两个参数pi，vi，
其中pi表示修理石桥的最小花费值，vi表示石桥需要的最小美化需求度。
今天,小G 已了解到修理厂共有m种不同的修理原料，对于第i种原料，可以对任意
一个石桥的美化度增加di，当然这也需要花费hi的费用。由于发货场的修理原料有限，
对于任意一种修理原料，只有一件，也就是说小G 只能选择购买和不购买，
对于第i种修理材料能成功修理第j个石桥的条件是：当且仅当hi ≥ pj，di ≥vj。
现在，已知这n个石桥修理的最小花费值，最小美化需求度，以及m种修理原料的费用，可对石桥增加的美化度值，
请你帮助小G完成这个修理任务。

Input
第一行包括两个正整数，n，m。
接下来 n 行中，每行包括两个正整数pi，vi。
接下来 m行中，每行包括两个正整数hi，di。

Output
只有一个整数，为最小修理花费。如果无法完成修理任务，则输出一个整数-1。

Sample Input
	2 3
	2 3
	5 9
	3 10
	3 5
	6 11

Sample Output
	9

Solution:
这是一道典型的贪心题！把石桥和修理方法都按美化需求度从大到小排序，一个一个石桥修理。
那么维护两个指针，对于一个石桥，就能知道“可能”可以修理的那些方案。之后，排除掉之前已经选过的那些，其中必有一个最佳方案。
显然， 最佳的一定是花费大于等于当前石桥且其花费最小的！

可是维护这样的集合有一些困难，复杂度一般为 O(NlogN) 这样再加上扫描本身的O(N)，是会时间超限的。

于是我们的平衡树算法——Splay，就隆重登场了！

只需基本的插入、删除和求后继操作就可以在 O(logN) 内实现了。
*/

#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode {
    TreeNode*parent;
    int val;
    ///son[0]:left   son[1]:right
    TreeNode*son[2];
    TreeNode(int val=0, TreeNode* parent=nullptr) {
        this->val=val;
        this->parent=parent;
        son[1]=son[0]=nullptr;
    }
};
TreeNode *root=nullptr;
///判断子节点是父节点的哪个儿子
///返回值即son[]数组的下标
inline bool son(TreeNode* parent, TreeNode* node) {
    return parent->son[1]==node;
}
///rotate(x)代表将x旋转到其父节点的位置上
inline void rotate(TreeNode*cur) {
    TreeNode * parent= cur->parent;
    TreeNode *graparent=parent->parent;
    bool a=son(parent,cur);
    bool b=!a;
    parent->son[a]=cur->son[b];
    if(cur->son[b]!=nullptr) {
        cur->son[b]->parent= parent;
    }
    cur->son[b]=parent;
    parent->parent=cur;
    cur->parent=graparent;
    if(graparent!=nullptr) {
        graparent->son[son(graparent,parent) ]=cur;
    } else {
        root=cur;
    }
}
///splay(x,y)将x结点旋转到y节点的某个儿子上,
///splay(x,NIL)表示将x旋转到根节点的位置上
inline void splay(TreeNode * x, TreeNode* y) {
    while(x->parent!=y) {
        TreeNode *parent=x->parent;
        TreeNode *graparent=parent->parent;
        if(graparent==y) {
            rotate(x);
        } else {
            if(son(graparent,parent) ^ son(parent,x)) {
                rotate(x);
                rotate(x);
            } else {
                rotate(parent);
                rotate(x);
            }
        }
    }
}
inline void insert(int val) {
    if(root==nullptr) {
        root=new TreeNode(val,nullptr);
        return ;
    }
    for(TreeNode *t=root ; t ; t=t->son[val >= t->val ]) {
        if(t->son[val >= t->val] ==nullptr) {
            t->son[val>=t->val]=new TreeNode(val,t);
            splay(t->son[val>=t->val],nullptr);
            return;
        }
    }
}

inline void erase(TreeNode * t) {
    if(t!=nullptr) {
        splay(t,nullptr);
        if(t->son[0]==nullptr) {
            root=t->son[1];
            if(root!=nullptr) {
                root->parent=nullptr;
            }
        } else {
            ///假如有左子树,找到左子树最靠右的结点,旋转到根节点的儿子上,
            ///此时他一定没有右儿子(根节点的左子树中不存在比他大的)
            ///把根节点的右子树接在这个节点的右儿子上即可
            TreeNode * left=t->son[0];
            while(left->son[1]!=nullptr) {
                left=left->son[1];
            }
            splay(left,t);
            root=left;
            root->parent=nullptr;
            left->son[1]=t->son[1];
            if(left->son[1]!=nullptr) {
                left->son[1]->parent=left;
            }
        }
        delete(t);
    }

}
inline TreeNode* find(int val) {
    if(root==nullptr) {
        return root;
    }
    TreeNode *tmp=root;
    while(true) {
        if(tmp->val <val) {
            tmp=tmp->son[1];
            continue;
        }
        if(tmp->son[0]!=nullptr) {
            TreeNode *cur=tmp->son[0];
            while(cur->val < val && cur->son[1]) {
                cur=cur->son[1];
            }
            if(cur->val>=val) {
                tmp=cur;
                continue;
            }
        }
        return tmp;
    }
}

const int maxn=500005;
typedef long long LL;
struct info {
    int x,y;
};
info bridge[maxn],mater[maxn];
LL ans=0;
void quicksort(info* ele, int start, int last) {
    if(start >= last) {
        return ;
    }
    int pivot=ele[start].y;
    int index= start;
    for(int i=start+1; i<=last; i++) {
        if(ele[i].y > pivot) {
            swap(ele[i],ele[++index]);
        }
    }
    swap(ele[start], ele[index]);
    quicksort(ele,start,index-1);
    quicksort(ele,index+1,last);
}

int main() {
    int n,m;
    while(scanf("%d%d",&n,&m) !=EOF) {
        root=nullptr;
        for(int i=0; i<n; i++) {
            scanf("%d%d",&bridge[i].x, &bridge[i].y);
        }
        for(int i=0; i<m; i++) {
            scanf("%d%d", &mater[i].x, &mater[i].y);
        }
        ans=0;
        quicksort(bridge,0,n-1);
        quicksort(mater,0,m-1);
        for(int i=0,j=0; i<n; i++) {
            while(j<m && mater[j].y >=bridge[i].y) {
                insert(mater[j++].x);
            }
            TreeNode* node=find(bridge[i].x);
            ans+=node->val;
            erase(node);
        }
        printf("%lld\n",ans);


    }

    return 0;
}
