class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if(nums.size()==0){
            return 0;
        }        
        vector<int>sums(nums.size()+1,0);
		/**
		sums[i]= nums[0]+...+nums[i-1]
		sums[k]= nums[0]+...+nums[k-1]
		sums[i]-sums[k] = nums[k]+...+nums[i]
		*/
        for(int i=1;i<=nums.size();i++){
            sums[i]=sums[i-1]+nums[i-1];
        }
		/**
		dp[i][j] : 第 1-i个数,划分成 j份的最大和 
		
		dp[i][j]= min(dp[i][j], max(dp[k][j-1], sums[i]-sums[k]))
		
		0...i-1 划分为j份	等价于 0...k-1划分为j-1份,剩余的k..i-1划分成1份
		然后取两边大的那个为分成j份的最大和,然后使这个和最小化
		注意k的取值,最小要为j-1,因为至少要有j-1个数,最大为i-1,因为要保证右边剩1个数
		*/
        vector<vector<int>>dp(nums.size()+1,vector<int>(m+1,INT_MAX));
		/**
		0个数,划分成0份为0
		*/
        dp[0][0]=0;
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=m;j++){
                for(int k=j-1;k<i;k++){
                    dp[i][j]=min(dp[i][j], max(dp[k][j-1], sums[i]-sums[k]) );
                }
            }
        }
        return dp[nums.size()][m];
    }
};