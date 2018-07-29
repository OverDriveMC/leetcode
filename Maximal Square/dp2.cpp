class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
           return 0;
        }
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>dp(n+1,0);
        int prev=0;
        int maxn=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp=dp[j+1];
                if(matrix[i][j]=='1'){
                    dp[j+1]= min(dp[j],min(dp[j+1],prev) )+1;
                    maxn=max(dp[j+1],maxn);
                }else{
                    dp[j+1]=0;
                }
                prev=temp;
            }
        }
        return maxn*maxn;
    }
};