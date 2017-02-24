#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> >res;
        vector<int>vec;
        dfs(candidates,target,0,vec,res,0);
        return res;
    }
    void dfs(vector<int>& candidates, int target,int sum,vector<int>&vec,vector<vector<int> >&res,int index) {
        //cout<<"index:"<<index<<"  "<<sum<<endl;
        if(sum>target){
            return ;
        }
        if(target==sum) {
            res.push_back(vec);
            return ;
        }
        if(index==candidates.size()) {
            return ;
        }
        ///继续选当前的(可能是选了N个之后继续选)
        vec.push_back(candidates[index]);
        dfs(candidates,target,sum+candidates[index],vec,res,index);
        vec.pop_back();
        ///不再选当前的(可能是选了N个之后不再选)
        dfs(candidates,target,sum,vec,res,index+1);
    }
};

int main() {
    vector<int>vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(7);
    Solution s;
    vector<vector<int> >res=s.combinationSum(vec,7);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout<<res[i][j]<<"   ";
        }
        cout<<endl;
    }
    return 0;
}
