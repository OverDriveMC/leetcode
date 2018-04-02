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
    ListNode *detectCycle(ListNode *head) {
        ListNode*first=head;
        ListNode*second=head;
        while(first!=NULL && first->next!=NULL && first->next->next!=NULL){
            first=first->next->next;
            second=second->next;
            if(first==second){
                second=head;
                while(first!=second){
                    first=first->next;
                    second=second->next;
                }
                return first;
            }
        }
        return NULL;
    }
};