#include <bits/stdc++.h>

using namespace std;
/**
*将1 放在下标为0的位置,将2放在下标为1的位置,将n放在下标为n-1的位置
*直接作交换，最后遍历一遍数组,发现相应位置不是对应值则是缺失的正数
*假如都不缺失,直接返回下一个数
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0){
            return 1;
        }
        for(int i=0;i<nums.size();){
            ///判断当前数应该在的位置是否存储了正确的数
            if(nums[i]>0  && nums[i]<nums.size() && nums[nums[i]-1]!=nums[i] ){
                swap(nums,i,nums[i]-1);
            }else{
                ///没出现交换的时候i再往后移动
                i++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if((i+1)!=nums[i]){
                return (i+1);
            }
        }
        return nums.size()+1;
    }
    void swap(vector<int> & nums,int i,int j){
        int temp=nums[j];
        nums[j]=nums[i];
        nums[i]=temp;
    }
};

int main(){
    Solution s;
    vector<int>vec;
    vec.push_back(-1);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(9);
    vec.push_back(10);
    cout<<s.firstMissingPositive(vec)<<endl;
    vec.clear();
    vec.push_back(1);
    vec.push_back(1);
    cout<<s.firstMissingPositive(vec)<<endl;
    return 0;
}
