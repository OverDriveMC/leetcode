#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        /**
        *这个判断还是必要的，不然的话假如p不是全*组合会越界
        */
        if(s==""){
            for(int i=0;i<p.length();i++){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
        }
        return match(s,p,0,0);
    }
    bool match(string s,string p ,int sp,int pp){
        if(pp==p.length()){
            return sp==s.length();
        }
        if(p[pp]=='*'){
            ///清除掉多余的*  例如****这种变为一个*即可
            while(pp<p.length() && p[pp]=='*'){
                pp++;
            }
            while(sp<=s.length()){
                ///通过*匹配0-N个不停的尝试
                if(match(s,p,sp,pp)){
                    return true;
                }
                sp++;
            }
        }else if(s[sp]==p[pp] || (sp<s.length() && p[pp]=='?')){
            return match(s,p,sp+1,pp+1);
        }
        return false;

    }
};
int main(){
    Solution s;
    cout<<s.isMatch("a","a*")<<endl;
    cout<<s.isMatch("","*")<<endl;
    cout<<s.isMatch("aa","a")<<endl;
    cout<<s.isMatch("aa","aa")<<endl;
    cout<<s.isMatch("aaa","aa")<<endl;
    cout<<s.isMatch("aa", "*")<<endl;
    cout<<s.isMatch("aa", "a*")<<endl;
    cout<<s.isMatch("ab", "?*")<<endl;
    cout<<s.isMatch("aab", "c*a*b")<<endl;
    return 0;
}
