#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head=new ListNode(0);
        head->next=NULL;
        ListNode*cur=head;
        int carry=0;
        //注意进位不为0
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode*temp=new ListNode(sum%10);
            temp->next=NULL;
            carry=sum/10;
            cur->next=temp;
            cur=cur->next;
        }
        return head->next;
    }
};

int  main(){
    ListNode* l1=new ListNode(2);
    l1->next=new ListNode(4);
    l1->next->next=new ListNode(3);
    l1->next->next->next=NULL;

    ListNode* l2=new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(4);
    l2->next->next->next=NULL;
    Solution s;
    ListNode*res=s.addTwoNumbers(l1,l2);
    while(res!=NULL){
        cout<<res->val<<"  "<<endl;
        res=res->next;
    }
}
