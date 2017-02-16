#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]==target){
                return true;
            }
            /**
            *假如nums[mid]>nums[hi]所以转折点在(mid,hi],[lo,mid)一定是没有
            *转折点的
            */
            if(nums[mid]>nums[hi]){
                if(nums[lo]<=target && target<nums[mid]){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
                /**
                *假如nums[mid]<nums[hi],那么说明[mid-hi]是没有转折点的
                */
            }else if(nums[mid]<nums[hi]){
                if(nums[mid]<target && target<=nums[hi]){
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }else{
                /**
                *说明nums[mid]==nums[hi],假如存在target,那么target一定在[low,hi]之间
                *既然nums[mid]!=target,而nums[mid]==nums[hi]那么hi所在位置一定不对,所以
                *减1继续二分
                */
                hi--;
            }
        }
        return false;
    }
};

int main(){
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    Solution s;
    cout<<s.search(nums,1)<<endl;
    cout<<s.search(nums,3)<<endl;
    cout<<s.search(nums,0)<<endl;
    return 0;
}
