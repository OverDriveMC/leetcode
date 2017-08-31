#include <bits/stdc++.h>

using namespace std;

const int maxn=105;
int dp[605][maxn][maxn];

/**
*dp[i][m][n]
*= max(dp[i-1][m][n],dp[i-1][m-zerocnt][onecnt])
* i为截止位置
* 到i截止,m个0,n个1
* 与不选择i,i-1为截止位置 m个0 ,n 个1
* 或 选择i, i-1为截止位置 m-zerocnt,n-onecnt个1
* 取最大值
*/

class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,0,sizeof(dp));

        vector<pair<int,int> >nums;
        trans(strs,nums);
        /**
        *从0-i ,所有0的个数大于 当前的并且1的个数大于当前的都可以更新。
        */
        for(int i=nums[0].first;i<=m;i++){
            for(int j=nums[0].second;j<=n;j++){
                dp[0][i][j]=1;
            }
        }

        for(int i=1;i<strs.size();i++){
            for(int zerocnt=0;zerocnt<=m;zerocnt++){
                for(int onecnt=0;onecnt<=n;onecnt++){
                    if(zerocnt>=nums[i].first && onecnt>=nums[i].second){
                        dp[i][zerocnt][onecnt]=max(max(dp[i][zerocnt][onecnt],dp[i-1][zerocnt][onecnt]),
                                               dp[i-1][zerocnt-nums[i].first][onecnt-nums[i].second]+1  );
                    }else{
                        dp[i][zerocnt][onecnt]=max(dp[i][zerocnt][onecnt],dp[i-1][zerocnt][onecnt]);
                    }
                }
            }
           // cout<<i<<"  "<<m<<"  "<<n<<"  "<<dp[i][m][n]<<endl;
        }
        return dp[strs.size()-1][m][n];
    }

    void trans(vector<string>&strs,vector<pair<int,int> >&nums){
        int zerocnt=0,onecnt=0;
        for(int i=0;i<strs.size();i++){
            zerocnt=0,onecnt=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0'){
                    zerocnt++;
                }else{
                    onecnt++;
                }
            }
            nums.push_back(make_pair(zerocnt,onecnt));
        }
    }
};


int main(){
    Solution s;
    vector<string>strs;
    strs.push_back("10");
    strs.push_back("0001");
    strs.push_back("111001");
    strs.push_back("1");
    strs.push_back("0");
    int res=s.findMaxForm(strs,5,3);
    cout<<res<<endl;

    strs.clear();
    strs.push_back("10");
    strs.push_back("0");
    strs.push_back("1");
    res=s.findMaxForm(strs,1,1);
    cout<<res<<endl;

    strs.clear();
    string arr[]={"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
    vector<string>strs2(arr,arr+30);
    res=s.findMaxForm(strs2,9,80);
    cout<<res<<endl;
    return 0;
}
