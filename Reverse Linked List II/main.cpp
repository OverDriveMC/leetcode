struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val):val(val),next(NULL)
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(m<0 || m>n){
			return head;
		}
		ListNode*first=NULL;
		n-=(m-1);
		///令first为指向开始反转的链表的前一个结点
		if(m==1){
			first=new ListNode(0);
		}else{
			first=head;
			//这里定义个新的变量修改,防止直接修改m
			int index=m;
			while(--index >1 && first){
				first=first->next;
			}
		}
		///m比链表长度长
		if(first==NULL){
			return head;
		}
		//tail记录链表反转之后的最后一个节点位置,用于之后和 下标>n的位置直接相连
		ListNode* tail= (m==1 ? head : first->next);
		///phead记录开始反转的位置
		ListNode* phead=( m==1 ? head : first->next);
		//防止phead为NULL
		while(n-- && phead){
			ListNode* tmp=phead;
			phead=phead->next;
			tmp->next=first->next;
			first->next=tmp;
		}
		tail->next=phead;
		return m==1 ? first->next : head;
    }
};