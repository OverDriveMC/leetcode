/**
给定一个整数数组,判定是否存在不相邻的下标i,j满足
nums[i]与nums[j]的差的绝对值小于t,并且i与j差的绝对值小于k
Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		//set保证有序
        set<long long>windows;
        for(int i=0;i<nums.size();i++){
            if(i>k){
				//每次把nums[i-k-1]这个元素删掉
                windows.erase(nums[i-k-1]);
            }
			/**
			注意,这里要用set.lower_bound()不能直接用low_bound(.begin(),.end(),xx)
			set<>::iterator不支持随机访问，所以直接当作普通的序列进行二分的时候就不是O(logn)的复杂度了。
			*/
            auto iter=windows.lower_bound((long long)nums[i]-t);
            if(iter!=windows.end() && (*iter -nums[i])<=t  ){
                return true;
            }
            windows.insert(nums[i]);
        }
        return false;
    }
};