/**
给定一个整形数组,以及一个整数k,判断是否存在两个不同的下标i,j
满足nums[i]==nums[j] 并且绝对位置不超过k
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>vis;
        for(int i=0;i<nums.size();i++){
            if(vis.find(nums[i])!=vis.end()){
                int index=vis[nums[i] ];
                if(i-index<=k){
                    return true;
                }
            }
            vis[nums[i] ]=i;
        }
        return false;
    }
};