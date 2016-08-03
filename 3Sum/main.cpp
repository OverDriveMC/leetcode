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
        ///注意，假如nums.size()不大于2的话，
        ///nums.size()是size_t类型，会强转
        for(int i=0;i<nums.size()-2;i++){
            ///判断是否和前一个数相同，防止重复
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            ///固定第一个，在后两个数里面求2Sum
            twoSum(nums,i+1,nums[i],vecs);
        }
        return vecs;
    }
    void twoSum(vector<int>& nums,int start,int first,vector<vector<int> >&vecs){
        int x=start,y=nums.size()-1;
        while(x<y){
            ///假如相同，则continue，防止重复
            ///只要相邻的不同，那么便能去除重复
            if(x>start && nums[x]==nums[x-1]  ){
                x++;
                continue;
            }
            int sum=nums[x]+nums[y];
            //cout<<nums[x]<<"  "<<nums[y]<<"  "<<first<<endl;
            if(sum+first==0){
                vector<int>vec;
                vec.push_back(first);
                vec.push_back(nums[x]);
                vec.push_back(nums[y]);
                vecs.push_back(vec);
                x++;
                continue;
            }if(sum+first>0){
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
