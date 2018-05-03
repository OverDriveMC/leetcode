#include<bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
		//主要是要分当前结点是否有重复元素两种情况
        if(head->val == head->next->val){
			//head一直往后指,直到head->next不与head相同
            while(head->next && head->val==head->next->val){
                head=head->next;
            }
			//head所在位置是重复元素出现的最后一个位置,返回删除head->next重复元素的结果
            return deleteDuplicates(head->next);
        }else{
			//假如当前结点没有重复元素,直接递归删除下一个结点的重复元素即可
            head->next=deleteDuplicates(head->next);
            return head;
        }
    }
};

int main(){
    ListNode *head=new ListNode(1);
    ListNode *second=new ListNode(1);
    head->next=second;
    ListNode *third=new ListNode(1);
    second->next=third;
    ListNode *forth=new ListNode(2);
    third->next=forth;
    ListNode *fifth=new ListNode(3);
    forth->next=fifth;
    Solution s;
    ListNode *newHead=s.deleteDuplicates(head);
    while(newHead){
        cout<<newHead->val<<endl;
        newHead=newHead->next;
    }
    return 0;
}
