/**
给定一个有序数组,删除重复元素,返回不重复元素数量
[1 1 2]  =>{1,2}  =2
pos=0 index=1   ====>pos=0   index=2
pos=0 index=2   ====>pos=1   swap(nums[1],nums[2])   index=3     
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return nums.size();
        }
		//pos:记录当前元素的最后一个不重复的位置
		///index即下标,开始往后移动,挨个遍历,将不重复的元素放入到pos所在的位置
        int pos=0,index=1;
        while(index<nums.size()){
            if(nums[pos]<nums[index]){
                pos++;
                if(pos!=index){
                    swap(nums[pos],nums[index]);
                }
            }
            index++;
        }
        //nums.erase(nums.begin()+pos+1,nums.end());
        return pos+1;
    }
};

int main(){
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(1);
////    vec.push_back(2);
////    vec.push_back(2);
////    vec.push_back(3);
////    vec.push_back(4);
////    vec.push_back(4);
////    vec.push_back(4);
    Solution s;
    cout<<s.removeDuplicates(vec)<<endl;
}
