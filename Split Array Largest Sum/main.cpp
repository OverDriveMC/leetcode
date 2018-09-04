class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxn=nums[0],sum=nums[0];
        for(int i=1;i<nums.size();i++){
            maxn=max(maxn, nums[i]);
            sum+=nums[i];
        }
        return binarySearch(nums, maxn, sum, m);
    }
    
    int binarySearch(vector<int>&nums, int begin, int last, int m){
        int res=begin;
        while(begin<=last){
            int mid=begin+(last-begin)/2;    
            int parts=partition(nums,mid);
            //假如parts>m说明划分点太小,需要扩大,parts<=m的时候,说明可以划分成功
            if(parts<=m){
                last=mid-1;
                res=mid;
            }else{
                begin=mid+1;
            }
        }
        return res;
    }
    int partition(vector<int>&nums, int val){
        //最少也是1份,每大于1次,part+1
        int part=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>val){
                sum=nums[i];
                part++;
            }
        }
        return part;
    }
};