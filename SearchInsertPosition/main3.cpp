#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        /**
        *当nums[mid]<target时,数组缩小[lo,mid],长度为mid-lo+1,至少减1
        *当nums[mid]>target时,数组缩小[mid,hi],长度为hi-mid+1,至少减1
        *最后一次循环开始的时候 lo==mid==hi,假如nums[mid]==target,直接返回
        *nums[mid]<target,lo=mid+1,lo位置要么是等于它,要么就是正好比它大的(也即插入位置)
        *nums[mid]>target,hi=mid-1=lo-1,lo位置为正好比它大的。
        *hi的位置只可能比它小
        */
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return lo;
    }
};
