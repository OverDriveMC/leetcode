#include<bits/stdc++.h>

using namespace std;
/**
*维护一个大小为k的堆，每次去堆顶的最小元素放到结果中，
*然后读取该元素的下一个元素放入堆中，重新维护好。
*因为每个链表是有序的，每次又是取当前k个元素中最小的，
*所以当所有链表都读完时结束，这个时候所有元素按从小到大放在结果链表中。
*这个算法每个元素要读取一次，即是k*n次，
*然后每次读取元素要把新元素插入堆中要logk的复杂度，
*所以总时间复杂度是O(nklogk)。空间复杂度是堆的大小，即为O(k)。
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty) return nullptr;
        vector<ListNode*>vec;
        /**
        *首先将所有不为NULL的首节点放入vec中
        */
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                vec.push_back(lists[i]);
            }
        }
        ///接下来使用所有的首节点建立小顶堆
        makeHeap(vec);
/*
        cout<<"建堆之后:"<<endl;
        for(int i=0;i<vec.size();i++){
            cout<<i<<":"<<vec[i]->val<<endl;
        }
        cout<<endl;
*/
        return mergeLists(vec);

    }
    void makeHeap(vector<ListNode*> &vec){
        int pos=vec.size()/2-1;
        while(pos>=0){
            int currentNodePos=pos;
            bool flag=false;
            while(!flag){
                int left=2*currentNodePos+1;
                int right=2*currentNodePos+2;
                ListNode* leftNode= left<vec.size()?vec[left]:NULL;
                ListNode* rightNode=right<vec.size()?vec[right]:NULL;
                if(leftNode!=NULL &&
                   (rightNode==NULL || leftNode->val<= rightNode->val)){
                    if(leftNode->val < vec[currentNodePos]->val){
                        ListNode* temp=leftNode;
                        vec[left]=vec[currentNodePos];
                        vec[currentNodePos]=temp;
                        ///pos指向左子节点的位置
                        currentNodePos=left;
                    }else{
                        flag=true;
                    }
                }else if(rightNode!=NULL &&
                         (leftNode==NULL || leftNode->val > rightNode->val)){
                    if(rightNode->val< vec[currentNodePos]->val){
                        ListNode* temp=rightNode;
                        vec[right]=vec[currentNodePos];
                        vec[currentNodePos]=temp;
                        ///pos指向右子节点的位置
                        currentNodePos=right;
                    }else{
                        flag=true;
                    }
                }else{
                    ///说明当前节点已经比左右子节点小了，不用下移了
                    flag=true;
                }
            }
            pos--;
        }
    }
    ListNode * mergeLists(vector<ListNode*>&vec){
        ListNode*head=new ListNode(0);
        ListNode*temp=head;
        while(!vec.empty()){

/*
            cout<<"vec size:"<<vec.size()<<endl;
            cout<<vec[0]->val<<endl;
*/

            temp->next=vec[0];
            temp=temp->next;
            if(vec.size()==1){
              break;
            }else if(vec[0]->next!=NULL){
                vec[0]=vec[0]->next;
            }else{
                vec[0]=vec[vec.size()-1];
                vec.erase(vec.end()-1);
            }
            adjustHeap(vec);
        }
        return head->next;
    }
    void adjustHeap(vector<ListNode*>&vec){
        bool flag=false;
        int pos=0;
        while(!flag){
            int left=pos*2+1;
            int right=pos*2+2;
            /**
            *定义节点，不然需要在if里面手动判断是否超出范围
            */
            ListNode*leftNode= left<vec.size()?vec[left]:NULL;
            ListNode*rightNode= right<vec.size()?vec[right]:NULL;
            ///注意<=，需要和下面的形成全集
            if(leftNode!=NULL &&
                (rightNode==NULL || leftNode->val<=rightNode->val)){
                if(leftNode->val <vec[pos]->val){
                    ListNode*temp=leftNode;
                    vec[left]=vec[pos];
                    vec[pos]=temp;
                    pos=left;
                }else{
                    flag=true;
                }
            }else if(rightNode!=NULL &&
                     (leftNode==NULL ||(leftNode->val>rightNode->val))){
                 if(rightNode->val <vec[pos]->val){
                    ListNode*temp=vec[right];
                    vec[right]=vec[pos];
                    vec[pos]=temp;
                    pos=right;
                 }else{
                    flag=true;
                 }
            }else{
                flag=true;
            }
        }
    }
};

int main(){
    Solution s;
    ListNode*node1=new ListNode(-1);
    ListNode*node2=new ListNode(1);
    //ListNode*node3=new ListNode(8);
    node1->next=node2;
    //node2->next=node3;

    ListNode*node4=new ListNode(-3);
    ListNode*node5=new ListNode(1);
    ListNode*node6=new ListNode(4);
    node4->next=node5;
    node5->next=node6;

    ListNode*node7=NULL;
    vector<ListNode*>vec;
    ListNode*node8=new ListNode(-2);
    ListNode*node9=new ListNode(-1);
    ListNode*node10=new ListNode(0);
    ListNode*node11=new ListNode(2);
    node8->next=node9;
    node9->next=node10;
    node10->next=node11;
    vec.push_back(node8);

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
