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
        while(lo<hi){
            /**
            *可以让mid通过+1偏向right
            *这样,当nums[mid]>target时,减少的区间为[mid,hi]长度为hi-mid+1
            *长度至少减少了1.
            *当nums[mid]<=target时,减少的区间为[lo,mid-1],长度为mid-lo
            *因为mid之间是+1之后的,所以必然大于lo，所以长度必然减少1
            */
            int mid=(lo+hi)/2+1;
            if(nums[mid]>target){
                hi=mid-1;
            }else{
                lo=mid;
            }
        }
        if(nums[hi]==target){
            res.push_back(hi);
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
