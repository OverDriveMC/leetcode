#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> >vecs;
        if(nums.size()<3){
            return vecs;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            twoSum(nums,i+1,0-nums[i],vecs);
        }
        return vecs;
    }
    void twoSum(vector<int>& nums,int start,int target,
                vector<vector<int> >& vecs){
        int x=start,y=nums.size()-1;
        int sum=0;
        while(x<y){
            sum=nums[x]+nums[y];
            if(sum ==target){
                /**
                *例如 -1 0 0 1 1
                *这种，一个数可能出现多次，所以需要去重
                */
                vector<int>vec;
                vec.push_back(0-target);
                vec.push_back(nums[x]);
                vec.push_back(nums[y]);
                sort(vec.begin(),vec.end());
                vecs.push_back(vec);
                x++;
            }else if(sum<target){
                x++;
            }else{
                y--;
            }
        }
    }

};

int main(){
    Solution s;
    vector<int>vec;
    vector<vector<int> >emptyvec=s.threeSum(vec);
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    vec.push_back(-4);
    vector<vector<int> >vecs=s.threeSum(vec);
    for(int i=0;i<vecs.size();i++){
        for(int j=0;j<vecs[i].size();j++){
            cout<<vecs[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}


