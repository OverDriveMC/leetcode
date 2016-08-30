#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp{
    ///val值越小，优先级越高
    bool operator()(ListNode*node1,ListNode* node2){
        return node1->val > node2->val;
    }

};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,cmp>heap;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) heap.push(lists[i]);
        }
        ListNode*head=new ListNode(0);
        ListNode*p=head;
        while(!heap.empty()){
            ListNode*minNode=heap.top();
            p->next=minNode;
            p=p->next;
            heap.pop();
            if(minNode->next){
                heap.push(minNode->next);
            }
        }
        return head->next;
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
