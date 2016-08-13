#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> >vecs;
        if(nums.size()<4){
            return vecs;
        }
        sort(nums.begin(),nums.end());
        int len=nums.size()-3;
        ///后面至少有三个数
        for(int i=0;i<len;i++){
            ///去除掉第一个数为同一个的
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            ///后面至少有两个数
            for(int j=i+1;j<nums.size()-2;j++){
                ///去除掉第二个数为同一个的
                if(j>(i+1) && nums[j]==nums[j-1]){
                    continue;
                }
                int x=j+1;
                int y=nums.size()-1;
                while(x<y){
                    int sum=nums[x]+nums[y]+nums[i]+nums[j];
                    if(sum==target){
                        vector<int>vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[x]);
                        vec.push_back(nums[y]);
                        vecs.push_back(vec);
                        x++;
                        y--;
                        while(x<y && nums[x]==nums[x-1]) x++;
                        while(x<y && nums[y]==nums[y+1]) y--;
                    }else if(sum>target){
                        y--;
                    }else{
                        x++;
                    }
                }
            }
        }
        return vecs;
    }
};


int main(){
    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(0);
//    nums.push_back(-1);
//    nums.push_back(0);
//    nums.push_back(-2);
//    nums.push_back(2);

    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);

    Solution s;
    vector<vector<int> > vecs=s.fourSum(nums,0);
    for(int i=0;i<vecs.size();i++){
        for(int j=0;j<vecs[i].size();j++){
            cout<<vecs[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
