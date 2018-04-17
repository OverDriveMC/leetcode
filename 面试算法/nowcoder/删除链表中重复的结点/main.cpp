/**
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
		/**
		增加一个头结点
		*/
        ListNode*first=new ListNode(0);
        first->next=pHead;
        ListNode*tmp=first;
		//当前结点和当前结点的下一个结点都不是NULL
        while(tmp && tmp->next){
			///每次是判断有没有结点和tmp->next相同
			///tmp为前一个结点,因为只有有前一个结点的指针才能删除下一个结点
            ListNode*judge=tmp->next->next;
			///找到第一个不和tmp->next值相同的位置
            while(judge!=NULL && judge->val == tmp->next->val){
                judge=judge->next;
            }
			///判断是否有重复结点
            if(judge!=tmp->next->next){
				///假如有,judge当前的指向是第一个不与tmp->next val相同的位置
				///注意,这个时候tmp不后移
				///因为可能出现 1 2 2 3 3这时删了 2 2,还需要1的指针来删除3 3
                tmp->next=judge;
            }else{
				///只有确保tmp->next没有值重复的元素才能往后移
                tmp=tmp->next;
            }
        }
        return first->next;
    }
};