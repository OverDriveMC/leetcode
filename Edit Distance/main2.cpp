class Solution {
public:
    int minDistance(string word1, string word2) {
        /**
        pre:dp[i-1][j-1]
        dp[i]: dp[i][j-1]  ===>dp[i][j]
        dp[i-1]: dp[i-1][j]
        */
        int m=word1.size();
        int n=word2.size();
        vector<int>dp(m+1,0);
        //讨论j=0的情况
        for(int i=0;i<=m;i++){
            dp[i]=i;
        }
        for(int j=1;j<=n;j++){
            // dp[0][j-1]
            int pre=j-1;
            //dp[0][j]=j  边界情况
            dp[0]=j;
            for(int i=1;i<=m;i++){
                //  dp[i]= dp[i][j-1],因为是结尾的时候pre=temp,所以相对下一轮来说pre=dp[i-1][j-1]
                int temp=dp[i];
                if(word1[i-1]==word2[j-1]){
                    dp[i]=pre;
                }else{
                    // dp[i-1]= dp[i-1][j]
                    //dp[i] = dp[i][j-1]
                    //最后的dp[i]=dp[i][j]
                    dp[i]=min(pre, min(dp[i-1], dp[i]))+1;
                }
                pre=temp;
            }
        }
        return dp[m];
    }
};