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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t=head;
        int cnt=0;
        while(t!=NULL){
            t=t->next;
            cnt++;
        }
        return removeNthFromStart(head,cnt-n+1);
    }

    ListNode* removeNthFromStart(ListNode* head, int n) {
        ///防止head节点为NULL，同时删除位置小于1
        if(head==NULL || n<1){
            return head;
        }
        ListNode*pre=NULL;
        ///找到删除节点的前一个位置
        for(int i=0;i<n-1;i++){
            if(i==0){
                pre=head;
            }else{
                pre=pre->next;
                ///节点数量不够的情况
                if(pre==NULL){
                    return head;
                }
            }
        }
        ///如果pre为NULL，证明要删除head节点
        if(pre==NULL){
            head=head->next;
        }else{
            pre->next=pre->next->next;
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
