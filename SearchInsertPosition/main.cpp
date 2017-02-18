#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0){
            return 0;
        }
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
        /**
        *二分的前提要保证target在数组里面,
        */
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<target){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        return lo;
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
