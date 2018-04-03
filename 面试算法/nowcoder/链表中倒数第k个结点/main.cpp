/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* first=pListHead;
		///先做减法
        while(--k && first){
            first=first->next;
        }
        if(first==NULL){
            return NULL;
        }
        ListNode*second=pListHead;
		//判断next是否为NULL
        while(first->next){
            second=second->next;
            first=first->next;
        }
        return second;
    }
};