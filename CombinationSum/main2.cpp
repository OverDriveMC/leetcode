#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>vec;
        vector<vector<int> >res;
        dfs(candidates,target,res,vec,0);
        return res;
    }
    void dfs(vector<int>& candidates, int target,vector<vector<int> >&res,vector<int>&vec,int index){
        if(target==0){
            res.push_back(vec);
            return ;
        }
        for(int i=index;i<candidates.size()&&  target>=candidates[i] ;i++){
            vec.push_back(candidates[i]);
            ///继续以i为起始位置,往后添加
            dfs(candidates,target-candidates[i],res,vec,i);
            ///不加入当前位置元素的情况
            vec.pop_back();
        }
    }
};

int main(){
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


