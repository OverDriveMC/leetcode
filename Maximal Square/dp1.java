class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		if(matrix.size()==0 || matrix[0].size()==0){
			return 0;
		}
		int m=matrix.size();
		int n=matrix[0].size();
		vector<vector<int> >dp(m, vector<int>(n,0));
		int maxn=0;
		//初始化边界位置
		for(int i=0;i<m;i++){
			if(matrix[i][0]=='1'){
				dp[i][0]=1;
				maxn=1;
			}
		}
		for(int i=0;i<n;i++){
			if(matrix[0][i]=='1'){
				dp[0][i]=1;
				maxn=1;
			}
		}
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				if(matrix[i][j]=='1'){
					dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
					maxn=max(dp[i][j],maxn);
				}else{
					dp[i][j]=0;
				}
			}
		}
		return maxn*maxn;
    }
};