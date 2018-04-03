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
		//判断一下链表是否为空
		///不为空的话找到最后一个节点开始返回
        if(pHead==NULL || pHead->next==NULL){
            return pHead;
        }
		//返回的prev是首节点,递归将下一个结点之后的链表反转
        ListNode*prev= ReverseList(pHead->next);
		///将当前结点置为后一个结点的next
        pHead->next->next=pHead;
		///当前结点的next置为NULL
        pHead->next=NULL;
		////返回首节点
        return prev;
    }
};