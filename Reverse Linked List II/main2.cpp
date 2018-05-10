/**
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* first=new ListNode(-1);
		first->next=head;
		ListNode*prev=first;
		int index=1;
		/**
		令head指向第m个结点,prev指向第m-1个结点
		*/
		while(index<m && head){
			prev=prev->next;
			head=head->next;
			index++;
		}
		/**
		每次移动的时候,主要考虑的是移动prev后面的结点原先所在的链会断
		所以先通过nextElem保存下来将要移动到prev结点后面的结点原先的后一个结点
		1——>2——>3——>4——>5
		此时prev=1  head=2
		第一轮循环将3移动到1之后,
		这时通过nextElem保存4所在的指针位置(head->next->next)
		之后让3的next指针指向2(即指向prev的后一个),即head->next->next=prev->next
		然后令prev的next指向3 这样就实现了将3插入到1 2之间
		最后再让2的next指针指向4,即head->next=nextElem
		最后完成1——>3——>2——>4——>5
		*/
		while(index<n  && head ){
			ListNode* nextElem=head->next->next;
			head->next->next=prev->next;
			prev->next=head->next;
			head->next=nextElem;
			index++;
		}
		return first->next;
	}
};