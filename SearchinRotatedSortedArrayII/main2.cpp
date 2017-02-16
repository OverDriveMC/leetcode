#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(target==nums[mid]){
                return true;
            }
            if(nums[lo]<nums[mid]){
                if(nums[lo]<=target && target<nums[mid]){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }else if(nums[lo]>nums[mid]){
                if(nums[mid]<target && target<=nums[hi]){
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }else{
                lo++;
            }
        }
        return false;
    }
};

int main(){
    vector<int>nums;
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(3);
    Solution s;
    cout<<s.search(nums,5)<<endl;
    cout<<s.search(nums,1)<<endl;
    cout<<s.search(nums,3)<<endl;
    cout<<s.search(nums,0)<<endl;
    return 0;
}
