#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        vector<ListNode*>vec;
        /**
        *首先将所有不为NULL的首节点放入vec中
        */
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                vec.push_back(lists[i]);
            }
        }
        ///接下来使用所有的首节点建立小顶堆
        makeHeap(vec);
        ///再把堆顶接入合并链表中
        ListNode* head=new ListNode(0);
        ListNode*p=head;
        while(!vec.empty()){
            auto minNode=vec[0];
            ///接入链表
            p->next=minNode;
            p=p->next;
            ///被选出的指针后移再加入小顶堆中
            ListNode*next=minNode->next;
            if(next){
                vec[0]=next;
            }else{
                ///假如next为NULL了，那么交换到最后，删掉就好了
                swap(vec[0],vec[vec.size()-1]);
                vec.pop_back();
            }
            minHeap(vec,0);
        }
        ///最后所有链表都为空时，返回合并链表的头指针
        return head->next;

    }
    ///建立小顶堆  自底向上
    void makeHeap(vector<ListNode*> &vec){
        ///从最后一个元素的父节点开始建立小顶堆
        for(int i=vec.size()/2-1;i>=0;i--){
            ///可以抽象出来一个操作，对
            ///i号元素做 下沉 操作
            minHeap(vec,i);
        }
    }
    /**
    *调整小顶堆，以第i个元素为根建立小顶堆
    *
    */
    void minHeap(vector<ListNode*> &vec,int pos){
            int left=2*pos+1;
            int right=left+1;
            int least=pos;
            if(left<vec.size() &&vec[left]->val <vec[least]->val){
                least=left;
            }
            if(right<vec.size() && vec[right]->val <vec[least]->val){
                least=right;
            }
            /**
            *假如最小值所在位置不为pos，说明发生了下沉操作
            *交换元素，同时再以新的位置建立小根堆
            */
            if(least!=pos){
                swap(vec[least],vec[pos]);
                minHeap(vec,least);
            }
    }
};

int main(){
    Solution s;
    ListNode*node1=new ListNode(-1);
    ListNode*node2=new ListNode(1);
    //ListNode*node3=new ListNode(8);
    node1->next=node2;
    //node2->next=node3;

    ListNode*node4=new ListNode(-3);
    ListNode*node5=new ListNode(1);
    ListNode*node6=new ListNode(4);
    node4->next=node5;
    node5->next=node6;

    ListNode*node7=NULL;
    vector<ListNode*>vec;
    ListNode*node8=new ListNode(-2);
    ListNode*node9=new ListNode(-1);
    ListNode*node10=new ListNode(0);
    ListNode*node11=new ListNode(2);
    node8->next=node9;
    node9->next=node10;
    node10->next=node11;
    vec.push_back(node8);

    vec.push_back(node1);
    vec.push_back(node4);
    vec.push_back(node7);

    ListNode*head=s.mergeKLists(vec);
    while(head!=NULL){
        cout<<head->val<<"  ";
        head=head->next;
    }
    cout<<endl;

    return 0;
}
