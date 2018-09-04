class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL || pHead2==NULL){
            return NULL;
        }
        ListNode * tmp=pHead1;
        while(tmp->next){
            tmp=tmp->next;
        }
		/**
		*将第一个链表的尾部指向第二个链表的头部,形成带环的链表,即找环的起点
		*/
        tmp->next=pHead2;
        ListNode *fast=pHead1;
        ListNode *slow=pHead1;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
			///快慢指针重合的时候,一个从头开始走,一个从相遇的位置开始走,在此相遇即为起点
            if(fast==slow){
                slow=pHead1;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                tmp->next=NULL;
                return slow;
            }
        }
		tmp->next=NULL;
        return NULL;
    }
};