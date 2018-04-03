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
    ListNode* ReverseList(ListNode* pHead) {
		//添加一个首节点
        ListNode* first=new ListNode(0);
        while(pHead!=NULL){
			//定义个临时变量保存下一个结点
            ListNode*tmp=pHead->next;
            pHead->next=first->next;
            first->next=pHead;
            pHead=tmp;
        }
        return first->next;
    }
};