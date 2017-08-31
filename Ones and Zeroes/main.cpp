#include<bits/stdc++.h>

using namespace std;



const  int maxn=105;
int dp[600][maxn][maxn];

class Solution {
public:
    void getNumberOfZeroAndOne(string str,int &zerocnt,int &onecnt){
        zerocnt=0;
        onecnt=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0'){
                zerocnt++;
            }else{
                onecnt++;
            }
        }
    };
    int solve(vector<string>& strs,int index ,int m, int n){
        if(m<0 || n<0){
            return 0;
        }
        if(m==0 && n==0){
            return 0;
        }
        if(index>=strs.size()){
            return 0;
        }
        if(dp[index][m][n]!=-1){
            return dp[index][m][n];
        }
        int zerocnt,onecnt;
        getNumberOfZeroAndOne(strs[index],zerocnt,onecnt);
        dp[index+1][m][n]=solve(strs,index+1,m,n);
        if(m>=zerocnt && n>= onecnt){
            dp[index+1][m-zerocnt][n-onecnt]=solve(strs,index+1,m-zerocnt,n-onecnt);
            dp[index][m][n]=max(dp[index+1][m][n],dp[index+1][m-zerocnt][n-onecnt]+1  );
        }else{
            dp[index][m][n]=dp[index+1][m][n];
        }

        return dp[index][m][n];
    }


    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,0,m,n);

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


