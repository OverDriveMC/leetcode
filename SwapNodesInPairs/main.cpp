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
    ListNode* swapPairs(ListNode* head) {
        ListNode*first=new ListNode(-1);
        first->next=head;
        ListNode*p=first;
        while(p->next!=NULL && p->next->next!=NULL){
            ListNode*temp=p->next;
            p->next=p->next->next;
            temp->next=p->next->next;
            p->next->next=temp;
            p=p->next->next;
        }

        return first->next;
    }
};

int main(){
    ListNode*node1=new ListNode(1);
    ListNode*node2=new ListNode(2);
    ListNode*node3=new ListNode(3);
    ListNode*node4=new ListNode(4);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;

    Solution s;
    ListNode*head=s.swapPairs(node1);
    while(head){
        cout<<head->val<<endl;
        head=head->next;
    }
    return 0;
}
