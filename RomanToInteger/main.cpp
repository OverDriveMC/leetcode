#include<bits/stdc++.h>
using namespace std;
/**
*(1)相同的数字连写、所表示的数等于这些数字相加得到的数、如：Ⅲ=3；
*(2)小的数字在大的数字的右边、所表示的数等于这些数字相加得到的数、
*    如：Ⅷ=8、Ⅻ=12；
*(3)小的数字、(限于 Ⅰ、X 和 C)在大的数字的左边、所表示的数
*   等于大数减小数得到的数、如：Ⅳ=4、Ⅸ=9；
*(4)正常使用时、连写的数字重复不得超过三次；
*(5)在一个数的上面画一条横线、表示这个数扩大 1000 倍。
*/
class Solution {
public:
    int romanToInt(string s) {
        /**
        *每次将当前的数字当成是字符串的末尾数字
        *先将当前的加进来，
        */
        int result=getNumber(s[0]);
        int current,left;
        for(int i=1;i<s.size();i++){
            current=getNumber(s[i]);
            left=getNumber(s[i-1]);
            if(left<current){
                /**
                *假如比左边的数字，那么
                *将左边数字在减去一次便可以了
                *(因为之前多加了一次)
                */
                result+=current-2*left;
            }else{
                result+=current;
            }
        }
        return result;
    }
    ///"MCMLXXXIV"
    int getNumber(char c){
        switch(c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
};
int main(){
    Solution s;
    cout<<s.romanToInt("XCIII")<<endl;
    cout<<s.romanToInt("XCV")<<endl;
    cout<<s.romanToInt("MCMLXXXIV")<<endl;
    cout<<s.romanToInt("MM")<<endl;
    return 0;
}
