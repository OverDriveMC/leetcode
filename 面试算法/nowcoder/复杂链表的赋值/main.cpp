/**
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL){
            return NULL;
        }
        RandomListNode*tmp=pHead;
		///每一个结点都在后面保存一个新的克隆结点
        while(tmp!=NULL){
            RandomListNode*copy=new RandomListNode(tmp->label);
            copy->next=tmp->next;
            tmp->next=copy;
            tmp=copy->next;
        }
        RandomListNode*copyHead=pHead->next;
        tmp=pHead;
		///更新克隆结点的random指针
        while(tmp->next->next){
			///结点的random指针可能为NULL
			//注意,只有结点的random指针不为NULL的时候,才有next
            if(tmp->random)
                tmp->next->random=tmp->random->next;
            tmp=tmp->next->next;
        }
        tmp=pHead;
        RandomListNode*ctmp=pHead->next;
        while(tmp ){
            tmp->next=tmp->next->next;
            tmp=tmp->next;
			///因为还要保证原来的指针的完整性,所以还要将原来的链表还原
			///所以最后要特判tmp是否到了最后一个
            if(tmp!=NULL){
                ctmp->next=tmp->next ;
                ctmp=ctmp->next;
            }
        }
        return copyHead;
    }
};