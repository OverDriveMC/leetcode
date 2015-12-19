#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>vis;
        for(int i=0;i<nums.size();i++){
            if(vis.find(target-nums[i])!=vis.end()){
                vector<int> v;
                v.push_back(vis[target-nums[i]]);
                v.push_back(i+1);
                return v;
            }else{
                vis.insert(make_pair(nums[i],i+1));
            }
        }
    }
};
int main(){
    Solution s;
    int a[]={1,2,3,4,5};
    vector<int>v=vector<int>(a,a+5);
    vector<int> c=s.twoSum(v,6);
    cout<<c[0]<<"  "<<c[1]<<endl;
}
