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
        if(head==nullptr || head->next==nullptr || k<=1){
            return head;
        }
        ///找到下一组的起点
        ListNode*next_group=head;
        for(int i=0;i<k;i++){
            if(next_group){
                next_group=next_group->next;
            }else{
                return head;
            }
        }
        ///递归函数返回下一组反转之后的新起点
        ListNode*new_next_group=reverseKGroup(next_group,k);
        ListNode*prev=nullptr,*cur=head;
        ///反转当前的组，当前的最后一个节点接到new_next_group前面
        ///结束条件为，cur反转到下一组之前未反转前的起点
        while(cur!=next_group){
            ///next记录未反转前的下一个
            ListNode*next=cur->next;
            ///假如prev为nullptr，说明是第一个，为该组翻转之后
            ///的最后一个，应该与下一组反转之后的新起点相连
            cur->next= prev? prev:new_next_group;
            prev=cur;
            cur=next;
        }
        return prev;
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
