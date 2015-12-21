#include<bits/stdc++.h>
using namespace std;
/**
区间dp
dp[i][j] 标记从i到j是否为回文串
dp[i][i]=true
dp[i][i+1]= s[i]==s[i+1] ?true :false
长度为2的单独讨论因为循环中，假如len=2
那么dp[i+1][len+i-2]  结果为dp[i+1][i]所以必须要分开算
dp[i][j]=dp[i+1][j-1] && s[i]==s[j] ? true : false
枚举长度即可
*/
class Solution {
public:
    string longestPalindrome(string s) {
        const int maxn=1005;
        bool dp[maxn][maxn];
        memset(dp,0,sizeof(dp));
        int maxL=1;
        int start=0;
        for(int i=0;i<s.length();i++){
            if(i!=(s.length()-1) &&  s[i]==s[i+1]){
                dp[i][i+1]=1;
                ///防止长度为2   abb
                maxL=2;
                start=i;
            }
            dp[i][i]=1;
        }
        for(int len=3;len<=s.length();len++){
            for(int i=0;i<=s.length()-len;i++){
                //cout<<i<<"  "<<i<<"   len:"<<len<<"  "<<dp[i+1][len+i-2]<<endl;
                if(s[i]==s[len+i-1] &&dp[i+1][len+i-2]){
                    dp[i][len+i-1]=1;
                    if(maxL<len){
                        start=i;
                        maxL=len;
                    }
                }
            }
        }
        //cout<<maxL<<endl;
        return s.substr(start,maxL);
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("aaaaa")<<endl;
    cout<<s.longestPalindrome("a")<<endl;
    cout<<s.longestPalindrome("aa")<<endl;
    cout<<s.longestPalindrome("aabbaa")<<endl;
}
