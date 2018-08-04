class Solution {
public:
    const int inf=0x3f3f3f3f;
    int maxProduct(vector<int>& nums) {
        int maxn=nums[0];
        int maxnpre=nums[0];
        int minpre=nums[0];
        int maxncur,mincur;
        for(int i=1;i<nums.size();i++){
			/**
			使用上一轮的
				最大值 * 当前值 , 最小值 * 当前值   当前值 
			里的最大值作为当前的最大值
			使用上一轮的
				最大值 * 当前值 , 最小值 * 当前值   当前值 
			里的最小值作为当前的最小值
			*/
            maxncur=max(max(maxnpre*nums[i],minpre*nums[i]),nums[i]);
            mincur=min(min(maxnpre*nums[i],minpre*nums[i]),nums[i]);
			//更新最大值
            maxn=max(maxncur,maxn);
			/**
			更新pre 的最大值,最小值
			*/
            maxnpre=maxncur;
            minpre=mincur;
        }
        return maxn;
    }
};