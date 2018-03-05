/**
除了一个数出现1次,其余的数都出现3次
*/

/**
6*(a+b+c) - 3*(2*a+2*b+c) = 4c
所以只要将a,b越掉即可
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int>set(nums.begin(),nums.end());
		//会越界
        long long sum1=0;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
        }
        long long sum2=0;
        for(int i : set){
            sum2+=i;
        }
        return (6*sum2-2*sum1)/4;
    }
};