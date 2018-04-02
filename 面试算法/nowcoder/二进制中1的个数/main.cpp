/**
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
/**
1110 
1110 & (1101)  ===> 1100
1100 & (1001)  ===> 1000
1000 & (0111)  ===> 0000

*/

class Solution {
public:
     int  NumberOf1(int n) {
         int cnt=0;
         while(n){
             n&=(n-1);
             cnt++;
        }
         return cnt;
     }
};
