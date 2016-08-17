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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ///添加一个空头结点
        ListNode *head=new ListNode(0);
        ListNode* temp=head;
        while(l1!=NULL || l2!=NULL){
            if(l2==NULL || (l1!=NULL && l1->val<=l2->val)){
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
            }else{
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
        }
        return head->next;
    }
};

int main(){
    ListNode * node1=new ListNode(3);
    ListNode * node2=new ListNode(5);
    ListNode * node3=new ListNode(7);
    node1->next=node2;
    node2->next=node3;

    ListNode * node4=new ListNode(1);
    ListNode * node5=new ListNode(4);
    ListNode * node6=new ListNode(10);
    node4->next=node5;
    node5->next=node6;

    Solution s;
    ListNode* ln=s.mergeTwoLists(node1,node4);
    while(ln!=NULL){
        cout<<ln->val<<endl;
        ln=ln->next;
    }
    return 0;
}
