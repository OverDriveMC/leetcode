#include <bits/stdc++.h>

using namespace  std;
/**
let's say nums looks like this:
[12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Because it's not fully sorted, we can't do normal binary search.
But here comes the trick:
If target is let's say 14, then we adjust nums to this,
where "inf" means infinity:
[12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf,
    inf, inf, inf, inf, inf, inf, inf, inf]

If target is let's say 7, then we adjust nums to this:
[-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4,
                5, 6, 7, 8, 9, 10, 11]
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size();
        while(lo<hi){
            int mid=(lo+hi)/2;
            ///查看nums[mid]与target是否是nums[0]同一边的
            int num=(nums[mid]<nums[0]) == (target<nums[0])
                ? nums[mid]
                : (target<nums[0] ? -INFINITY : INFINITY );
            ///之后会将数组构造成一个完全的递增序列
            if(num<target){
                lo=mid+1;
            }else if(num>target){
                hi=mid;
            }else{
                return mid;
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
