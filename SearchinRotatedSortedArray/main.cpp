#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<1){
            return -1;
        }
        int demarpos=demarcationPos(nums);
        //cout<<"分界点:"<<demarpos<<endl;
        if(target<nums[demarpos]){
            return -1;
        }else{
            if(demarpos==0){
                return binarySearch(0,nums.size()-1,nums,target);
            }else if(target>=nums[0]){
                return binarySearch(0,demarpos-1,nums,target);
            }else{
                return binarySearch(demarpos,nums.size()-1,nums,target);
            }
        }

    }
    int binarySearch(int left,int right,vector<int>& nums, int target){
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return -1;
    }
    /**
    *找出分界点位置,最小元素的位置
    */
    int demarcationPos(const vector<int>& nums){
        int left=0,right=nums.size()-1;
        int mid;
        while(nums[left]>nums[right]){
            mid=left+(right-left)/2;
            if(nums[mid]>=nums[left]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};

int main(){
    Solution s;
    vector<int>nums;
    nums.push_back(3);
    nums.push_back(1);
    cout<<s.search(nums,1)<<endl;
    cout<<s.search(nums,3)<<endl;
    return 0;
}
