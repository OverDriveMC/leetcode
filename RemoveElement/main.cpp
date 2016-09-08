#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos=0,index=0;
        while(index<nums.size()){
            if(val!=nums[index]){
                nums[pos++]=nums[index];
//                if(pos!=index){
//                    swap(nums[pos],nums[index]);
//                }
//                pos++;
            }
            index++;
        }
        return pos;
    }
};

int main(){
    vector<int>vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    Solution s;
    //cout<<s.removeElement(vec,3)<<endl;
    cout<<s.removeElement(vec,2)<<endl;
    cout<<s.removeElement(vec,4)<<endl;
}
