#include<bits/stdc++.h>

using namespace std ;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxn=0;
        for(int i=0;i<nums.size();i++){
			///假如能到当前位置
            if(maxn>=i){
				///那么更新是否能跳到更远的位置
                maxn=max(i+nums[i],maxn);
            }else{
                return false;
            }
        }
        if(maxn>=nums.size()-1){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution s;
    vector<int>vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(4);
    cout<<s.canJump(vec)<<endl;
    return 0;
}
