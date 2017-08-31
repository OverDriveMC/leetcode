#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
        const int maxn=105;
        int dp[maxn][maxn];

        memset(dp,0,sizeof(dp));
        int czero=0,cone=0;
        for(int i=0;i<strs.size();i++){
            czero=0,cone=0;
            for(int j=0;j<strs[i].size();j++){
                switch(strs[i][j]){
                case '1':
                    cone++;
                    break;
                default:
                    czero++;
                }
            }


            for(int zerocnt=m;zerocnt>=0;zerocnt--){
                for(int onecnt=n;onecnt>=0;onecnt--){
                    if(zerocnt>=czero && onecnt>=cone){
                        dp[zerocnt][onecnt]=max(dp[zerocnt][onecnt],
                                               dp[zerocnt-czero][onecnt-cone]+1  );
                    }
                }
            }
           // cout<<i<<"  "<<m<<"  "<<n<<"  "<<dp[i][m][n]<<endl;
        }
        return dp[m][n];
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
