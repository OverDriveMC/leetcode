class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        int dp[]=new int[nums.length];
        dp[0]=nums[0];
        int maxn=dp[0];
        for(int i=1;i<nums.length;i++){
			//接着选,从当前位置重新开始
            dp[i]=Math.max(dp[i-1]+nums[i],nums[i]);
            maxn=Math.max(dp[i],maxn);
        }
        return maxn;
    }
}