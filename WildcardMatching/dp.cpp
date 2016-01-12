#include<bits/stdc++.h>
using namespace std;
/**
用dp[i][j]表示字符串s的前i个字符和字符串p的前j个字符是否匹配
当p[j-1]不为 *的情况下

当s[i-1]==p[j-1] 或者p[j-1]=='?' 并且dp[i-1][j-1]为true时
dp[i][j]= true

当p[j-1]为*的时候
假设dp[i-1][j-1]==true  那么*可以匹配 s中i-1 ->s.length()中的所有字符
所以都为true
假如dp[i][j-1]==true  那么*可以匹配 i->s.length()中的所有字符
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        /**
        *防止s为空，p为***的组合
        */
        if(s.length()==0){
            for(int i=0;i<p.length();i++){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
        }


        const int maxn=1005;
        bool dp[maxn][maxn];
        memset(dp,0,sizeof(dp));
        dp[0][0]=true;
        for(int j=1;j<=p.length();j++){
            for(int i=1;i<=s.length();i++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    if(dp[i-1][j-1]){
                        dp[i][j]=true;
                    }
                }else if(p[j-1]=='*'){
                    if(dp[i-1][j-1]){
                        for(int k=i-1;k<=s.length();k++){
                            dp[k][j]=true;
                        }
                        break;
                    }else if(dp[i][j-1]){
                        for(int k=i;k<=s.length();k++){
                            dp[k][j]=true;
                        }
                        break;
                    }
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};

int main(){
    Solution s;
    cout<<s.isMatch("aa","a")<<endl;
    cout<<s.isMatch("aa","aa")<<endl;
    cout<<s.isMatch("aaa","aa")<<endl;
    cout<<s.isMatch("aa", "*")<<endl;
    cout<<s.isMatch("aa", "a*")<<endl;
    cout<<s.isMatch("ab", "?*")<<endl;
    cout<<s.isMatch("aab", "c*a*b")<<endl;
    return 0;
}








