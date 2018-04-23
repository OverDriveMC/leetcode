/**
链表上的快速排序
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	//不包含头,不包含尾
    void sortHelper(ListNode*first,ListNode*last){
        if(first->next==last){
            return ;
        }
        ListNode*pivot=first->next;
        ListNode*tmp=pivot;
        while(tmp && tmp->next!=last){
        /**
		每次判断的都是tmp的下一个元素
		假如比pivot的值小,那么移动到first后面
		*/
			if(pivot->val > tmp->next->val){
                ListNode*t=first->next;
                first->next=tmp->next;
                tmp->next=tmp->next->next;
                first->next->next=t;
            }else{
                tmp=tmp->next;
            }
        }
        sortHelper(first,pivot);
		//排除掉所有相等的元素
        while(pivot && pivot->next!=last && pivot->next->val ==pivot->val){
            pivot=pivot->next;
        }
        sortHelper(pivot, last);
        
    }
    
    ListNode* sortList(ListNode* head) {
        ListNode*first=new ListNode(0);
        first->next=head;
        sortHelper(first,NULL);
        return first->next;
    }
};