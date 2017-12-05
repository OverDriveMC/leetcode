class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
        }
        if(sum%k!=0){
            return false;
        }
        sum/=k;
        int[] vis=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            vis[i]=0;
        }
		
        return dfs(0,nums,sum,vis,sum,k);
    }
    public boolean dfs(int index,int[]nums,int sum,int vis[],int target,int k){
		///当k等于0时,说明找到了K组和为target的
		///因为可能有多个组合能满足和为target,如果某些组合先组了会导致其它的数组不成和为sum的
		///所以要统计所有的可能才能退出
		if(k==0){
			return true;
		}
        if(sum==0){	
			///当sum减到0时,说明成功找到一组,再去找剩下的k-1组即可
            return dfs(0,nums,target,vis,target,k-1);
        }
        for(int i=index;i<nums.length;i++){
        	if(vis[i]!=0){
        		continue;
        	}
			///首先标记为1表示使用了该数
			vis[i]=1;
            if(dfs(i+1,nums,sum-nums[i],vis,target,k)){
                return true;
            }else{
				///假如发现使用该数不能满足,然后置位0
				vis[i]=0;
			}
        }
        return false;
    }
/*   
    public static void main(String[] args) {
		///注意这组案例
		int[]nums={2,2,10,5,2,7,2,2,13};
		Solution s=new Solution();
		System.out.println(s.canPartitionKSubsets(nums,3)); 
	}
*/
}