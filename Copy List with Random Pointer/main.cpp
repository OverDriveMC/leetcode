/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/**
* 对链表进行深层copy
* 链表除了有next指针,还有一个random指针
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode*iter=head;
        while(iter!=NULL){
			//首先将每个节点都copy一份,放在该节点后面
            RandomListNode* copy=new RandomListNode(iter->label);
            copy->next=iter->next;
            iter->next=copy;
            iter=copy->next;
        }
        iter=head;
        while(iter!=NULL){
			///复制节点的random节点正好也在源节点的random节点后面
            if(iter->random!=NULL){
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        RandomListNode* copyHead=new RandomListNode(0);
        iter=head;
        RandomListNode* copyiter=copyHead;
		///最后分离copy节点和原节点
        while(iter!=NULL){
            copyiter->next=iter->next;
            iter->next=iter->next->next;
            iter=iter->next;
            copyiter=copyiter->next;
        }
        return copyHead->next;
    }
};