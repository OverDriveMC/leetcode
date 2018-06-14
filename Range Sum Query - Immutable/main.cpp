/**
给定一个整数数组,计算下标从i——j(i<=j的元素和)

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

*/
/**
0   1   2    3   4    5
-2  0   3   -5   2    -1                  nums
0   -2  -2   1   -4   -2    -3            presum 
所以计算0-2   presum:presum[3]-presum[0]= 1-0=1
presum[3]=nums[0]+nums[1]+nums[2]
presum[0]=0
*/


class NumArray {
public:
    NumArray(vector<int> nums) {
		//一开始先添加一个0
        presum.push_back(0);
        for(int i=0;i<nums.size();i++){
            presum.push_back(presum.back()+nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
		//这样前缀和实际是从1开始
        return presum[j+1]-presum[i];
    }
private:
    vector<int>presum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */