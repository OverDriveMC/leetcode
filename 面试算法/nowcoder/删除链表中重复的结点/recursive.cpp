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
        if(pHead==NULL || pHead->next==NULL){
			//注意,这里要返回pHead,pHead不一定为NULL,可能是倒数第二个元素
            return pHead;
        }
		/**
			假如当前结点出现重复元素
		*/
        if(pHead->val == pHead->next->val){
            ListNode * diff=pHead->next->next;
            while(diff!=NULL && pHead->val ==diff->val){
                diff=diff->next;
            }
			/**
				diff是第一个不与当前结点重复的,
				继续递归,看diff是否与后面的有重复元素
				返回第一个没有重复元素的
			*/
            return deleteDuplication(diff);
        }else{
			/**
				假如当前结点没有重复元素,开始判断下一个结点是否有重复元素
				同时返回当前结点
			*/
            pHead->next=deleteDuplication(pHead->next);
            return pHead;
        }
    }
};