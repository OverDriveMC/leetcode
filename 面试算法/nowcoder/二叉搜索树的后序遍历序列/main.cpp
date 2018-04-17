/**
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
/*
BST的后序序列的合法序列是,对于一个序列S,最后一个元素是x(也就是根),如果去掉最后一个元素的序列为T,
那么T满足:T可以分成两段,前一段(左子树)小于x,后一段(右子树)大于x,且这两段(子树)都是合法的后序序列
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0){
            return false;
        }
        return judge(sequence,0,sequence.size()-1);
    }
    bool judge(vector<int>&seq, int start,int end){
        if(end-start<=1){
            return true;
        }
		///这里必须是end-1,可能[start,end)都比end小,假如初始化为>=end,pos会不更新,一直jusge(start,pos)的位置
		///会溢出
        int pos=end-1;
        for(int i=start;i<end;i++){
            if(seq[i]>seq[end]){
                pos=i-1;
                break;
            }
        }
        for(int i=pos+1;i<end;i++){
            if(seq[i]<seq[end]){
                return false;
            }
        }
        return judge(seq, start, pos) && judge(seq, pos+1, end-1);
    }
};