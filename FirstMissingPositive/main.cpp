#include <bits/stdc++.h>

using namespace std;

/**
*假如不重复可以考虑求和然后做差
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0){
            return 1;
        }
        int maxn=nums[0],sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                maxn=max(maxn,nums[i]);
                sum+=nums[i];

            }
        }
        int missing=(maxn+1)*maxn/2-sum;
        return missing==0 ? maxn+1 : missing ;
    }
};

int main(){
    Solution s;
    vector<int>vec;
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(-1);
    vec.push_back(1);
    cout<<s.firstMissingPositive(vec)<<endl;
    return 0;
}
