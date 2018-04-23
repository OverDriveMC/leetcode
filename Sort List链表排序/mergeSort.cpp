/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*prev=NULL;
		/**
		快慢指针找中心节点,同时记录慢指针前一个结点
		*/
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
		//将慢指针前一个结点的next设置为NULL
        prev->next=NULL;
		//归并
        ListNode*left=sortList(head);
        ListNode*right=sortList(slow);
		//merge
        return merge(left,right);
    }
    ListNode*merge(ListNode* left, ListNode*right){
        ListNode*head=new ListNode(0);
        ListNode*tmp=head;
        while(left!=NULL || right!=NULL){
            if(left==NULL || (right!=NULL && right->val < left->val )){
                tmp->next=right;
                right=right->next;
            }else{
                tmp->next=left;
                left=left->next;
            }
            tmp=tmp->next;
        }
        ListNode*res=head->next;
        delete head;
        return res;
    }
    
};