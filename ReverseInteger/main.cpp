#include<bits/stdc++.h>

using namespace std;
/**
当用abs(-32768)和labs(-2147483648)时，
结果分别是-32768和-2147483648。
这点需要注意，所以强转了之后再求的绝对值

*/
class Solution {
public:
    int reverse(int x) {
        bool flag=x >0 ? true :false;
        long long temp=x;
        ///需要转化成long long 之后再求绝对值
        temp= temp>0 ? temp : 0-temp;
        long long res=0;
        while(temp){
            res*=10;
            res+=temp%10;
            temp/=10;
        }
        /**
        *注意转化为正数之后，
        *最大正数和最小负数的范围是不同的
        */
        if(flag){
            return res > 0x7fffffff ? 0 : res;
        }else{
            return res >0x80000000 ? 0 : (0-res);
        }
    }
};

int main(){
    Solution s;
    int x=1534236469;
    cout<<s.reverse(x)<<endl;
    cout<<s.reverse(-2147483648)<<endl;
    cout<<s.reverse(1234)<<endl;
    cout<<s.reverse(-1234)<<endl;
    cout<<s.reverse(1)<<endl;
    return 0;
}
