/**
https://leetcode.com/problems/integer-break/description/
将整数拆分为至少两个正整数相加,并且使他们的积最大
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

方案1：dp
令dp[n]为n对应的最大积
那么递归方程为: dp[n] =max(i* dp[n-i] , max(dp[n], i*(n-i))  )  (i从1到n-1)
边界:dp[1]=1
时间复杂度O(n^2)

因为dp[n-i]可能小于n-i,所以分两种情况,一种是不拆开n-i,一种是拆开(拆开就选择最大的)
*/

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                /**
                    可以选择拆成最大积
                    或者可以选择不拆开
                    dp[k]可能小于k,例如2
                */
                dp[i]=max( j* dp[i-j],max( j*(i-j) ,dp[i]) );
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout<<s.integerBreak(10)<<endl;
}
