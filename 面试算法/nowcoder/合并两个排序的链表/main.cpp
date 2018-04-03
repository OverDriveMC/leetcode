/**
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode*first=new ListNode(0);
/**
注意定义个tmp,不要直接用first
*/
        ListNode*tmp=first;
        while(pHead1!=NULL || pHead2!=NULL){
            if(pHead1==NULL || (pHead2!=NULL  && pHead1->val>=pHead2->val)){
                tmp->next=pHead2;
                pHead2=pHead2->next;
            }else{
                tmp->next=pHead1;
                pHead1=pHead1->next;
            }
            tmp=tmp->next;
        }
        tmp->next=NULL;
        return first->next;
    }
};