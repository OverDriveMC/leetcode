/**
根据均值不等式(n个数的算术平均数大于等于它们的几何平均数)

An=(x1 + x2 + ... + xn) /n  >= Gn= nsquare(x1x2...xn)
等式在x1=x2=x3=...=xn 的时候取等号
假设把n拆分成 实数,那么设每一个数为x,一共有n/x个数
积为f(x)= x^(n/x),
求导：f′(x)=(n/x^2)  *  x^(n/x)  * (1-lnx)
当x=e时取极大值
因为规定 x为整数,所以取得x越靠近e越好,那么2<e<3
所以取3是最好的,取不到就取2

幂运算时间复杂度为O(lgn),所以算法复杂度为O(lgn)
*/

class Solution {
public:
    int integerBreak(int n) {
        if(n<=2){
            return 1;
        }else if(n==3){
            return 2;
        }else if(n%3==0){
            return pow(3,n/3);
        }else if(n%3==1){
			/**
			例如7
			7-4之后就可以被3整除
			*/
            return 4*pow(3,(n-4)/3);
        }else{
			/**
			例如5,5-2之后就可以被3整除
			*/
            return 2*pow(3,(n-2)/3);
        }
    }
};
