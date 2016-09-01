#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return nums.size();
        }
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
