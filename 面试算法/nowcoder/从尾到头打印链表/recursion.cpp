/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>res;
		///注意判断空链表
        if(head==NULL){
            return res;
        }
        printListFromTailToHead(head,res);
        return res;
    }
    void printListFromTailToHead(ListNode* node, vector<int>&res) {
        if(node->next==NULL){
            res.push_back(node->val);
            return ;    
        }
		///先加入后一个
        printListFromTailToHead(node->next,res);
		///再加入当前的
        res.push_back(node->val);
    }
};