#include <bits/stdc++.h>

using namespace std;
/**
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /**
        if(nums.size()<=2){
            return nums;
        }
        */
        vector<int>res;
        int m=0,n=0,cm=0,cn=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                cm++;
            }else if(nums[i]==n){
                cn++;
            }else if(cm==0){
                m=nums[i];
                cm=1;
            }else if(cn==0){
                n=nums[i];
                cn=1;
            }else{
                cm--;
                cn--;
            }
        }
        cm=0,cn=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                cm++;
            }else if(nums[i]==n){
                cn++;
            }
        }
        if(cm> nums.size()/3 ){
            res.push_back(m);
        }
        if(cn >nums.size()/3){
            res.push_back(n);
        }
        return res;
    }
};
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(1);
    Solution s;
    vector<int>res= s.majorityElement(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
