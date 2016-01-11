#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s,p,0,0);
    }
    bool match(string s,string p,int sp,int pp){
        ///是否双方都到了末尾
        if(sp==s.length()){
            return pp==p.length();
        }
        if(p[pp+1] =='*' ){
            while(s[sp]==p[pp] || (p[pp]=='.' && sp<s)  ){

            }
            ///假如都不匹配，直接跳过 这两个字符
            return match(s,p,s,pp+2);
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
    return 0;
}
