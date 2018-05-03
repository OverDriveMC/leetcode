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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*first=new ListNode(-1);
        first->next=head;
        ListNode*tmp=first;
        while(tmp->next && tmp->next->next){
            ListNode*judge=tmp->next;
            while(judge->next && tmp->next->val==judge->next->val){
                judge=judge->next;
            }
			//关键就是判断当前元素是否有重复元素
            if(judge==tmp->next){
                tmp=tmp->next;
            }else{
                tmp->next=judge->next;
            }
        }
        
        return first->next;
    }
};