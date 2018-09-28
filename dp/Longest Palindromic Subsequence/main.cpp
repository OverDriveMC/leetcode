/**
最长回文子序列
Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()<=1){
            return s.size();
        }
        vector<vector<int>>dp(s.size(), vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;
        }
		//枚举长度,区间dp
        for(int len=2;len<=s.size();len++){
            for(int i=0;i<=s.size()-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};