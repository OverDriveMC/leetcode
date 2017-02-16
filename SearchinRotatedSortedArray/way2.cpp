#include <bits/stdc++.h>

using namespace std;
/**
假设本身是个升序序列,从左向右,如果左边的点比右边的点小,说明这两个点
之间是有序的,不存在旋转点,否则的话,说明有一个旋转点,导致了不再有序。
因为只有一个旋转点,所以一分为二,肯定有一半有序的,所以还是用二分法,
不过要先判断左半边有序还是右半边有序,如果左半边有序,则直接将目标和
左半边的边界比较，就知道在不在左半边了，否则就在右半边。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]==target){
                return mid;
            }
            ///假如左边是有序的
            if(nums[lo]<=nums[mid]){
                ///之前判过相等了,所以只有可能mid-1或 mid+1
                if(nums[lo]<=target &&target<nums[mid]){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }else{
                if(nums[mid]<target && target<=nums[hi]){
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
        }
        return -1;
    }
};


int main(){
    vector<int>nums;
    nums.push_back(3);
    nums.push_back(1);
    Solution s;
    cout<<s.search(nums,3)<<endl;
    cout<<s.search(nums,1)<<endl;
    cout<<s.search(nums,0)<<endl;
	return 0;
}
