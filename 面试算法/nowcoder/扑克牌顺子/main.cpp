/**
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,
并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()==0){
            return false;
        }
        sort(numbers.begin(),numbers.end());
        int cnt=0;
        int pos=0;
        while(pos<numbers.size() && numbers[pos]==0){
            cnt++;
            pos++;
        }
        for(int i=pos+1;i<numbers.size();i++){
            int diff=numbers[i]-numbers[i-1];
            if(diff>1){
                if(diff-1>cnt){
                    return false;
                }
                cnt=cnt-diff+1;
            }else if(diff<1){
				//注意不能是对子
                return false;
            }
        }
        return true;
    }
};