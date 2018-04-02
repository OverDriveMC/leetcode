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
        stack<int>s;
		//采用一个栈模拟
        while(head!=NULL){
            s.push(head->val);
            head=head->next;
        }
        vector<int>res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};