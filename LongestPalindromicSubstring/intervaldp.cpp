#include<bits/stdc++.h>
using namespace std;
/**
����dp
dp[i][j] ��Ǵ�i��j�Ƿ�Ϊ���Ĵ�
dp[i][i]=true
dp[i][i+1]= s[i]==s[i+1] ?true :false
����Ϊ2�ĵ���������Ϊѭ���У�����len=2
��ôdp[i+1][len+i-2]  ���Ϊdp[i+1][i]���Ա���Ҫ�ֿ���
dp[i][j]=dp[i+1][j-1] && s[i]==s[j] ? true : false
ö�ٳ��ȼ���
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
                ///��ֹ����Ϊ2   abb
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
