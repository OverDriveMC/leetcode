#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        if(nums.size()==0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(nums[mid]<target){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        if(nums[lo]==target){
            res.push_back(lo);
        }else{
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }

        hi=nums.size()-1;
        while(lo<hi-1){
            int mid=(lo+hi)/2;
            if(nums[mid]>target){
                hi=mid-1;
            }else{
                lo=mid;
            }
        }
        if(nums[hi]==target){
            res.push_back(hi);
        }else if(nums[lo]==target){
            res.push_back(lo);
        }
        return res;
    }
};

int main(){
    vector<int>vec;
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(8);
    vec.push_back(10);

    Solution s;
    vector<int>res=s.searchRange(vec,8);
    cout<<"["<<res[0]<<","<<res[1]<<"]"<<endl;
    res=s.searchRange(vec,10);
    cout<<"["<<res[0]<<","<<res[1]<<"]"<<endl;
    res=s.searchRange(vec,7);
    cout<<"["<<res[0]<<","<<res[1]<<"]"<<endl;

    vec.clear();
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    res=s.searchRange(vec,2);
    cout<<"["<<res[0]<<","<<res[1]<<"]"<<endl;
    return 0;
}
