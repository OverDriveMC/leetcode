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
/**
*每k个元素反转
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1){
            return head;
        }
        ListNode *first=new ListNode(-1);
        first->next=head;
        int cnt=0;
        ///指向要反转的链表的前一个节点
        ListNode*start=first;
        ListNode*current=start;
        while(current->next!=NULL){
            current=current->next;
            cnt++;
            ///k个节点
            if(cnt==k){
                ListNode*prev=start->next;
                ListNode*toMove=prev->next;
                ListNode*end=current->next;
                while(prev->next!=end){
                    prev->next=toMove->next;
                    toMove->next=start->next;
                    start->next=toMove;
                    toMove=prev->next;
                }
                ///数量清0
                cnt=0;
                ///开始start节点要改成当前的最后一个节点
                ///current节点也要改成当前的最后一个节点
                start=prev;
                current=prev;
            }
        }
        return first->next;
    }
};

int main(){
    ListNode *node1=new ListNode(1);
    ListNode *node2=new ListNode(2);
    ListNode *node3=new ListNode(3);
    ListNode *node4=new ListNode(4);
    ListNode *node5=new ListNode(5);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    Solution s;
    ListNode *head=s.reverseKGroup(node1,3);
    while(head!=NULL){
        cout<<head->val<<endl;
        head=head->next;
    }
    return 0;
}
