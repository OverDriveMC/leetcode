#include<bits/stdc++.h>
using namespace std;
///-4 -1 -1 0 1 2
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> >vecs;
        if(nums.size()<3){
            return vecs;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            find(nums,i+1,vecs);
        }
        return vecs;
    }
    void find(vector<int>& nums,int start,vector<vector<int> >&vecs){
        int x=start,y=nums.size()-1;
        while(x<y){
            int sum=nums[x]+nums[y]+nums[start-1];
            if(sum==0){
                vector<int>vec;
                vec.push_back(nums[start-1]);
                vec.push_back(nums[x]);
                vec.push_back(nums[y]);
                vecs.push_back(vec);
                ///去掉重复元素
                while(x<y && nums[x]==nums[x+1]) x++;
                while(x<y && nums[y]==nums[y-1]) y--;
                x++;
                y--;
                continue;
            }if(sum>0){
                y--;
            }else{
                x++;
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
