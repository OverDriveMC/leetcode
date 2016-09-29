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
        ///���ܳ���0x80000000���������Ϊlong long
        long long res=0;
        while(a>=b){
            long long c=b;
            ///�±��0��ʼ��1<<0=1
            for(int i=0;a>=c;i++){
                a-=c;
                res+=(1<<i);
//                cout<<"a:"<<a<<" C:"<<c<<" res:"<<res<<" i:"<<i<<endl;
                c<<=1;
            }
        }
        res=((dividend^divisor)>>31)?(-res):res;
        ///����ֱ�ӷ��أ���Ҫ���ж�һ���Ƿ�������С����С
        ///���ܳ��� 0x80000000 -1���֣�ת��int֮��Խ��
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
