#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> >res;
        sort(candidates.begin(),candidates.end());
        vector<int>vec;
        dfs(candidates,target,vec,res,0);
        ///有重复的数字,去重
//        sort(res.begin(),res.end());
//        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
    void dfs(vector<int>& candidates, int target,vector<int> &vec, vector<vector<int> >&res,int index){
//        cout<<"index:"<<index<<"  ";
//        for(int i=0;i<vec.size();i++){
//            cout<<vec[i]<<"  ";
//        }
//        cout<<endl;

        //当小于0的时候,结束返回
        if(target<0){
            return ;
        }
        if(target==0){
            //复制vec内的元素,构建一个新的vector添加进入res,之后对vec的所有操作不会影响到res
            res.push_back(vec);
            return;
        }
        for(int i=index;i<candidates.size() && target >= candidates[i];i++){
            ///同一个字母开头的去掉
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            vec.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],vec,res,i+1);
            vec.pop_back();
        }
    }
};

int main(){
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(10);
    Solution s;
    vector<vector<int> >res=s.combinationSum2(vec,8);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
