/**
计算回文子串的个数
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        /**
		dp[i][j]表示i-j之间的串是不是回文串
		dp[i][j]=1 ========> s[i]==s[j] && dp[i-1][j+1]=1
		否则dp[i+1][j-1]=0
		*/
		int dp[s.size()][s.size()];
        memset(dp,0,sizeof(dp));
        int res=0;
        for(int i=0; i<s.size(); i++) {
            dp[i][i]=1;
            res++;
            if((i+1<s.size()) && s[i]==s[i+1]){
                dp[i][i+1]=1;
                res++;
            }
        }

        for(int len=3; len<=s.size(); len++) {
            for(int i=0; i<=s.size()-len; i++) {
                int j=i+len-1;
                if(dp[i+1][j-1] && s[i]==s[j]) {
                    dp[i][j]=1;
                    res++;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    cout<<s.countSubstrings("aaa")<<endl;
    return 0;
}
