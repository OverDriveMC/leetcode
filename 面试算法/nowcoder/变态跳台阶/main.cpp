/**
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
f(1)=1  一种跳发
f(2)=f(1)+f(0)  两种跳法,一次1阶,一次2阶
f(n)=f(n-1)+f(n-2)+...+f(0)   n种跳法

f(n-1)=f(n-1)+f(n-2)+...+f(0)
=====>f(n)=f(n-1)+f(n-1)=2*f(n-1)
所以f(n)=2^(n-1)


*/


class Solution {
public:
    int jumpFloorII(int number) {
        if(number<=0){
            return -1;
        }
        int res=1;
        int x=2;
        number--;
        while(number){
            if(number&1){
                res*=x;
            }
            x*=x;
            number>>=1;
        }
        return res;
    }
};