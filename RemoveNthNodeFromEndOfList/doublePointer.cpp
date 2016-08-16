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
        if(head==NULL || n<=0){
            return head;
        }
        ///快慢指针，相隔 n步，第一个指针走到尾，
        ///第二个指针的下一个即为要删除的
        /// 1 2 3 4 5   5
        ListNode* quick=head;
        n--;
        while(quick->next!=NULL && n){
            n--;
            quick=quick->next;
        }
        ///cout<<"快指针指向:"<<quick->val<<endl;
        ///数量不足的情况
        ///当n==0的时候说明是正好
        if(quick->next ==NULL && n){ return head;}
        ListNode*slow=NULL;
        while(quick->next!=NULL){
            quick=quick->next;
            if(slow==NULL){
                slow=head;
            }else{
                slow=slow->next;
            }
        }
        ///cout<<"慢节点指向:"<<slow->val<<endl;
        ///假如为NULL，说明删除首节点
        if(slow==NULL){
            head=head->next;
        }else{
            slow->next=slow->next->next;
        }
        return head;
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
    ListNode *first=s.removeNthFromEnd(&head,2);
    while(first!=NULL){
        cout<<first->val<<endl;
        first=first->next;
    }
    return 0;
}
