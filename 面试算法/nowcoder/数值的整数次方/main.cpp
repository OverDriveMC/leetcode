/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/
class Solution {
public:
    double Power(double base, int exponent) {
        double res=1;
        int n;
		//需要考虑指数小于0的情况
        if(exponent<0){
            n=-exponent;
        }else{
            n=exponent;
        }
        while(n){
            if(n&1){
                res*=base;
            }
            base*=base;
            n>>=1;
        }
        return exponent>=0 ? res : 1/res;
    }
};
