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
        ListNode* p=pListHead,*q=pListHead;
        int i;
        for(i=0; p!=NULL ;i++){
            if(i>=k){
                q=q->next;
            }
            p=p->next;
        }
        return i>=k ? q : NULL;
    }
};