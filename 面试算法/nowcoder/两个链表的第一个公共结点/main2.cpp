/**
输入两个链表，找出它们的第一个公共结点。
*/
/*
假如List1长度:a+b,List2长度:b+n,且a<b
那么p1会先走到链表尾部,这时p2走到a+n位置,将p1换成List2的头部
接着p2再走b+n-(n+a)=b-a走到链表尾部,这时p1也走到List2的b-a位置,还差a步就到可能的第一个公共节点
将p2换成List1头部,p2走a步也到可能的第一个公共结点。如果恰好p1==p2,那么p1就是第一个公共结点
或者p1和p2一起走n步到达列表尾部,二者没有公共结点,退出循环
时间复杂度O(n+a+b)
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode*p1=pHead1,*p2=pHead2;
        while(p1!=p2){
            p1= (p1==NULL) ? pHead2 : p1->next;
            p2= (p2==NULL) ? pHead1 : p2->next;
        }
        return p1;
    }
};