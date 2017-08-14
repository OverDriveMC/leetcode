#include<bits/stdc++.h>
using namespace std;
/**
计算759+674
1.假如不考虑进位,得到323
2.假如只考虑进位,得到1110
3.这两个数相加 323+1110=1433即结果
不考虑进位的和:
0+0=0   0+1=1  1+0=1  1+1=0
这就是异或的运算规则
如果只考虑进位的和
0+0=0 0+1=0 1+0=0 1+1=1
这是与运算的结果
第三步将两者相加时,递归调用这个算法,终止条件是进位为0时,直接返回第一步的结果
*/

class Solution {
public:
    int getSum(int a, int b) {
        return b==0 ? a : getSum(a^b,(a&b)<<1);
/*
        if(b==0){
            return a;
        }
        int temp=a ^ b;
        ///第一位进位始终为0
        b=(a&b)<<1;
        return getSum(temp,b);
*/
    }
};


int main(){
    Solution s;
    cout<<s.getSum(1,2)<<endl;
    cout<<s.getSum(3,2)<<endl;
}
