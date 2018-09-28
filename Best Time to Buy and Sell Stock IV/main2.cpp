#include<bits/stdc++.h>
using namespace std;
/**
dp[i][j] :第j天最多执行i笔交易的最大收益
已经知道第j天最多已经执行i笔交易的最大收益,可以基于第j-1天已经执行i笔交易的最大收益
和第j天正好完成第i笔交易的最大收益
dp[i][j]=max(dp[i][j-1],  dp[i-1][jj] +prices[j] -prices[jj] ) (jj in range [0,j-1])
        =max(dp[i][j-1], max(dp[i-1][jj] - prices[jj]) + prices[j])
dp[0][j]: 0 笔交易 利润为 0
dp[i][0]: 同一天,price不变,利润也是0
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        if(len<=1){
            return 0;
        }
        if(k >= len/2){
            int sum=0;
            for(int i=1;i<len;i++){
                sum+=max(0,prices[i]-prices[i-1]);
            }
            return sum;
        }
        int **dp=new int*[k+1];
        for(int i=0;i<=k;i++){
            dp[i]=new int[len];
        }

        for(int i=0;i<len;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=k;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=k;i++){
            int localMax=dp[i-1][0] -prices[0];
            for(int j=1;j<len;j++){
                dp[i][j]=max(dp[i][j-1],prices[j] +localMax);
                localMax=max( localMax , dp[i-1][j]-prices[j]);
            }
        }
        return dp[k][len-1];
    }
};
int main(){
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(3);
    Solution s;
    cout<<s.maxProfit(0, prices)<<endl;
}
