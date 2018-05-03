/**
1 1 1 2 2 3
idx=0 nums={1}
idx=1 nums={1,1}
idx=2 num=1  num==nums[0]  nums={1,1}
idx=3 num=2  nums={1,1,2}
idx=4 num=2  nums={1,1,2,2}
idx=5 num=3  nums={1,1,2,2,3}
*/

class Solution {
    public int removeDuplicates(int[] nums) {
        int idx=0;
        for(int num : nums){
            if(idx<2 || num>nums[idx-2]){
                nums[idx++]=num;
            }
        }
        return idx;
    }
}