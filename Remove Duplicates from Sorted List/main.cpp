/**
删除链表中的重复元素
Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3

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
    ListNode* deleteDuplicates(ListNode* head) {
        /**
		这种不需要添加头结点
		*/
		ListNode*cur=head;
        while(cur){
			/**
			直接往后找与当前元素不相同的元素即可
			*/
            ListNode*tmp=cur->next;
            while(tmp && cur->val == tmp->val){
				//假如相同,删除当前元素
                cur->next=tmp->next;
                tmp=cur->next;
            }
            cur=cur->next;
        }
        return head;
    }
};