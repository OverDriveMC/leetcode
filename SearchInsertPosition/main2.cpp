#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int lo=0,hi=nums.size()-1;
       /**
        *循环不变式:
        *如果原始数组中存在比key小的元素,那么原始数组
        *中符合要求的元素存在于待处理的数组
        */
       while(lo<hi-1){
            int mid=(lo+hi)/2;
            /**
            *假如nums[mid]<target,那么数组缩小的范围[lo,mid-1],长度为
            *mid-lo,如果要保证减小的话,那么必然lo<hi-1
            *假如nums[mid]>=target,那么数组缩小的范围[mid,hi],长度为
            *hi-mid+1,每次必然减小1
            */
            if(nums[mid]<target){
                lo=mid;
            }else{
                hi=mid-1;
            }
       }
       /**
       *循环跳出后,符合的x要么在最终的数组中,要么既不在最终的
       *数组中也不再原始的数组中(因为每一次循环都是剔除不符合要求的下标)
       *数组长度为2时,right=left+1,先检查right在检查left
       *数组长度为1时,right=left
       */
       if(nums[hi]<target){
            return hi+1;
       }else if(nums[hi]==target){
            return hi;
       }else if(nums[lo]<target){
            return lo+1;
       }else{
            return lo;
       }
    }
};
int main(){
    Solution s;
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    cout<<s.searchInsert(nums,5)<<endl;
    cout<<s.searchInsert(nums,2)<<endl;
    cout<<s.searchInsert(nums,7)<<endl;
    cout<<s.searchInsert(nums,0)<<endl;
    return 0;
}
