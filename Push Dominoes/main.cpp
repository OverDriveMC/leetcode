/**
https://leetcode.com/problems/push-dominoes/description/
多米诺骨牌
Example 1:

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
Example 2:

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
如果s[i]='L',表示它往左倒
如果s[i]='R',表示它往右倒
s[i-1]='R'  s[i]='.'  s[i+1]='L'  则中间的不会倒

Here is another idea that focus on 'L' and 'R'.
'R......R' => 'RRRRRRRR'
'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'
'L......R' => 'L......R'
'L......L' => 'LLLLLLLL'
所以一共有如上几种情况,为了统一所有情况,所以考虑将原字符串开头加上'L',结尾补上'R'
然后每次考虑  特殊字符(L,R)之间的字符(不考虑头,不考虑尾),
i代表开头,j代表结尾
i>0的时候,每次把开头加进去
因为每次都只添加中间的,所以最后的R,会自动不添加
*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes='L'+dominoes+'R';
        stringstream ss;
        for(int i=0,j=1;j<dominoes.size();j++){
            if(dominoes[j]=='.'){
                continue;
            }
            if(i>0){
                ss<<dominoes[i];
            }
            int interval=j-i-1;
			/**
			L...L   R...R的情况
			*/
            if(dominoes[i]==dominoes[j]){
                ss<<string(interval, dominoes[i]);    
            }else if(dominoes[i]=='L' && dominoes[j]=='R'){
				//'L......R' => 'L......R'的情况
                ss<<string(interval,'.');
            }else{
				//'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'的情况
                ss<<string(interval/2,'R')<<string(interval%2,'.')<<string(interval/2,'L');
            }
			//每次处理完特殊情况,将当前的结束点赋值到起始点(因为每次都是添加的中间的,所以结束点没有添加
			//下次在遇到的时候,会因为i>0,直接添加进来),同时也保证了多出来的R不会被添加进来
            i=j;
            
        }
        return ss.str();
    }
};