#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<=0){
            return NULL;
        }
        ListNode*head=NULL;
        for(int i=0;i<lists.size();i++){
            head=mergeTwo(head,lists[i]);
        }
        return head;
    }
    ListNode* mergeTwo(ListNode* node1,ListNode* node2){
        ListNode*head=new ListNode(0);
        ListNode*temp=head;
        while(node1!=NULL || node2!=NULL){
            if(node1==NULL || (node2!=NULL && node1->val >=node2->val)){
                temp->next=node2;
                temp=temp->next;
                node2=node2->next;
            }else{
                temp->next=node1;
                temp=temp->next;
                node1=node1->next;
            }
        }
        return head->next;
    }
};

int main(){
    Solution s;
    ListNode*node1=new ListNode(2);
    ListNode*node2=new ListNode(5);
    ListNode*node3=new ListNode(8);
    node1->next=node2;
    node2->next=node3;

    ListNode*node4=new ListNode(1);
    ListNode*node5=new ListNode(3);
    ListNode*node6=new ListNode(10);
    node4->next=node5;
    node5->next=node6;

    ListNode*node7=NULL;
    vector<ListNode*>vec;
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
