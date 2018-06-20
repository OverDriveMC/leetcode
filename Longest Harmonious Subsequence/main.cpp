class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        map<int,int>freq;
		//默认value初始化为1
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
		//先排序
        sort(nums.begin(),nums.end());
        int maxn=0;
        for(int i=0;i< nums.size()-1;i++){
            int cur=freq[nums[i]];
            //查找最大值
			if(freq.find(nums[i]+1)!=freq.end() ){
                maxn=max(maxn,cur+freq[nums[i]+1 ]);
            }
        }
        return maxn;
    }
};