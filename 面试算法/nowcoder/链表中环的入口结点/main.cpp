/**
一个链表中包含环，请找出该链表的环的入口结点。
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL){
            return pHead;
        }
        ListNode*fast=pHead;
        ListNode*slow=pHead;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
			///快慢指针,一个每次走2步,一个每次走1步,
			///相遇之后,一个从头开始走,一个从当前位置走
			///再次相遇,说明到入口位置
            if(fast==slow){
                slow=pHead;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};