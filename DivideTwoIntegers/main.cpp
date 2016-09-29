#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MAX_INT=0x7fffffff;
    const int MIN_INT=0x80000000;
    int divide(int dividend, int divisor) {
        long long a=dividend>0 ? dividend : -(long long)dividend;
        long long b=divisor>0 ?divisor : -(long long)divisor;
        if(b==0){
            return MAX_INT;
        }
        ///可能出现0x80000000溢出，所以为long long
        long long res=0;
        while(a>=b){
            long long c=b;
            ///下标从0开始，1<<0=1
            for(int i=0;a>=c;i++){
                a-=c;
                res+=(1<<i);
//                cout<<"a:"<<a<<" C:"<<c<<" res:"<<res<<" i:"<<i<<endl;
                c<<=1;
            }
        }
        res=((dividend^divisor)>>31)?(-res):res;
        ///不能直接返回，需要在判断一次是否大于最大小于最小
        ///可能出现 0x80000000 -1这种，转成int之后越界
        if(res>MAX_INT || res<MIN_INT){
            res=MAX_INT;
        }
        return res;
    }


};

int main(){
    Solution s;
    int a=0xffffffff;
    cout<<s.divide(20,5)<<endl;
    cout<<s.divide(20,3)<<endl;
    cout<<s.divide(-20,5)<<endl;
    cout<<s.divide(-20,3)<<endl;
    //cout<<s.divide(-20,0)<<endl;
    cout<<s.divide(-2147483648,-1)<<endl;
    cout<<s.divide(2147483647,1)<<endl;
    cout<<s.divide(-2147483648,1)<<endl;
    cout<<s.divide(-2147483648,-1)<<endl;
}
