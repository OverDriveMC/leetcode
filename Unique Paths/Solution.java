class Solution {
    public int uniquePaths(int m, int n) {
        int [][]dp=new int[m+1][n+1];
        for(int i=0;i<=m;i++){
            dp[i][1]=1;
        }
        for(int i=0;i<=n;i++){
            dp[1][i]=1;
        }
        
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
				//到达当前位置有两种方式,一种是从上面下来,一种是从左边过来
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
	
	public static void main(String[]args){
		System.out.println(new Solution().uniquePaths(2,3));
	}
	
}