#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
*假设总共有k个list，每个list的最大长度是n，
*那么运行时间满足递推式T(k) = 2T(k/2)+O(n*k)。
*(mergeTwo最大的时间复杂度是合并最后两个链表，所有的节点进行合并
     所以O(n*k))
*根据主定理，可以算出算法的总复杂度是O(nklogk)。
*空间复杂度的话是递归栈的大小O(logk)。
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<=0){
            return NULL;
        }
        return mergeKLists(lists,0,lists.size()-1);
    }
    ///分治
    ListNode* mergeKLists(vector<ListNode*>& lists,int left,int right){
        if(left==right){
            return lists[left];
        }else if(right>left){
            int mid=(left+right)>>1;
            ListNode* lefthead=mergeKLists(lists,left,mid);
            ListNode* righthead=mergeKLists(lists,mid+1,right);
            return mergeTwo(lefthead,righthead);
        }else{
            return NULL;
        }
    }
    /**
    *注意，到时是new新节点，还是改变源节点
    *new ListNode();
    */
    ListNode* mergeTwo(ListNode* left, ListNode * right){
        ListNode *head=new ListNode(0);
        ListNode*temp=head;
        while(left && right){
            if(left->val<right->val){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        if(left) temp->next=left;
        if(right) temp->next=right;
        return head->next;
    }
};

int main(){
    Solution s;
    ListNode*node1=new ListNode(2);
    ListNode*node2=new ListNode(5);
    ListNode*node3=new ListNode(8);
    node1->next=node2;
    node2->next=node3;

    ListNode*node4=new ListNode(1);
    ListNode*node5=new ListNode(3);
    ListNode*node6=new ListNode(10);
    node4->next=node5;
    node5->next=node6;

    ListNode*node7=NULL;
    vector<ListNode*>vec;
    vec.push_back(node1);
    vec.push_back(node4);
    vec.push_back(node7);
    ListNode*head=s.mergeKLists(vec);
    while(head!=NULL){
        cout<<head->val<<"  ";
        head=head->next;
    }
    cout<<endl;

    return 0;
}
