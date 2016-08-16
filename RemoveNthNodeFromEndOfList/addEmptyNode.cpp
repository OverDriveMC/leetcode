/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    ///补一个空头，这样就不用考虑删除第一个节点的问题了
        ListNode* first=new ListNode(0);
        first->next=head;
        ListNode*quick=first;
        ///1 2 3 4 5  5
        while(quick->next!=NULL && n){
            quick=quick->next;
            n--;
        }
        ///cout<<"快指针位置:"<<quick->val<<endl;
        ///当快指针已经指向末尾时，n还不为0
        ///说明删除长度不够
        if(quick->next==NULL && n){
            return head;
        }
        ListNode *slow=first;
        while(quick->next!=NULL){
            slow=slow->next;
            quick=quick->next;
        }
        ///cout<<"慢指针位置："<<slow->val<<endl;
        slow->next=slow->next->next;
        ///不能直接返回head，因为可能head被删掉了
        return first->next;
    }
};

int main(){
    ListNode head(1);
    ListNode node2(2);
    head.next=&node2;
    ListNode  node3(3);
    node2.next=&node3;
    ListNode  node4(4);
    node3.next=&node4;
    ListNode  node5(5);
    node4.next=&node5;
    Solution s;
    ListNode *first=s.removeNthFromEnd(&head,5);
    while(first!=NULL){
        cout<<first->val<<endl;
        first=first->next;
    }
    return 0;
}

