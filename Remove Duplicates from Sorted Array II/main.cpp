/**
给定有序数组,每个元素至多出现2次,求元素个数
Example 1:
Given nums = [1,1,1,2,2,3],
return length = 5, {1,1,2,2,3}

Example 2:
Given nums = [0,0,1,1,1,1,2,3,3],

return length = 7, {0,0,1,1,2,3,3}
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos=0,index=1;
		//添加一个times记录出现次数
        int times=1;
        while(index<nums.size()){
            if(nums[pos]!=nums[index]){
				//不相等时times复位为1
                pos++;
                times=1;
                swap(nums[pos],nums[index]);
            }else{
				///假如相等时,times还是1的话,可以添加,否则不添加
                if(times==1){
                    pos++;
                    swap(nums[pos],nums[index]);
                    times++;
                }
            }
            index++;
        }
        return nums.size()==0 ? 0 :pos+1;
    }
};

int main(){
    vector<int>nums={0,0,1,1,1,1,2,3,3};
    Solution s;
    cout<<s.removeDuplicates(nums)<<endl;
    return 0;
}
