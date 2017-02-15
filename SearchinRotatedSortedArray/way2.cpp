#include <bits/stdc++.h>

using namespace std;
/**
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
            if(nums[lo]<=nums[mid]){
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
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    Solution s;
    cout<<s.search(nums,4)<<endl;
    cout<<s.search(nums,7)<<endl;
    cout<<s.search(nums,0)<<endl;
    cout<<s.search(nums,2)<<endl;
    cout<<s.search(nums,8)<<endl;
	return 0;
}
