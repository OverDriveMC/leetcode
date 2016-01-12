#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s,p,0,0);
    }
    bool match(string s,string p,int sp,int pp){
        ///是否双方都到了末尾
        /**
        *要先判断pp是否到末尾
        *因为即使s到末尾了，还是可能相同
        *例如 a   ab*
        */
        if(pp==p.length()){
            return sp==s.length();
        }
        if(p[pp+1] =='*' ){
            while(s[sp]==p[pp] || (p[pp]=='.' && sp<s.length())  ){
                /**
                *如果s[sp]==p[pp]那么 * 可以匹配0个到多个
                *接下来与s[sp]相同的字符
                */
                if(match(s,p,sp,pp+2)){
                    return true;
                }
                sp++;
            }
            ///直到失配不等之后，跳过该 p[pp]*字符
            ///s[sp]!=p[pp]
            return match(s,p,sp,pp+2);
        }else{
            if(s[sp]==p[pp] || p[pp]=='.' ){
                return match(s,p,sp+1,pp+1);
            }else{
                return false;
            }
        }
    }
};

int main(){
    Solution s;
    cout<<s.isMatch("aa","a")<<endl;
    cout<<s.isMatch("aa","aa")<<endl;
    cout<<s.isMatch("aaa","aa")<<endl;
    cout<<s.isMatch("aa", "a*")<<endl;
    cout<<s.isMatch("aa", ".*")<<endl;
    cout<<s.isMatch("ab", ".*")<<endl;
    cout<<s.isMatch("aab", "c*a*b")<<endl;
    cout<<s.isMatch("a", "ab*")<<endl;
    cout<<s.isMatch("bbbba", ".*a*a")<<endl;
    return 0;
}
