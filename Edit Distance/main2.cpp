#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minDistance(string word1,string word2){
        int m=word1.size(),n=word2.size();
        vector<int> dp(m+1,0);
        for(int i=1;i<=m;i++){
            dp[i]=i;
        }
        for(int j=1;j<=n;j++ ){
            int pre=dp[0];
            dp[0]=j;
            for(int i=1;i<=m ;i++){
                int temp=dp[i];
                if(word1[i-1] == word2[j-1]){
                    dp[i]=pre;
                }else{
                    dp[i]=min(pre+1,min(dp[i]+1,dp[i-1]+1));
                }
                pre=temp;
            }
        }
        return dp[m];

    }


};
