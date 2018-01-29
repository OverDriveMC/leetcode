/*
dp[i][j]=dp[i][j-1]+dp[i-1][j]

dp[m][n]=dp[n][m] 
假设n>m, n只控制轮数
所以cur[j]=dp[i][j-1]   pre[j]=dp[i-1][j]
所以cur[j]=cur[j-1]+pre[j]

但是最后计算完cur[m-1]的时候,会将cur,pre结果交换,所以实际最后应该返回pre[m-1]
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n){
            return uniquePaths(n,m);
        }
        
        vector<int> pre(m,1);
        vector<int> cur(m,1);
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                cur[j]=cur[j-1]+pre[j];
            }
            swap(cur,pre);
        }
        return pre[m-1];
    }
};

/**
也可以不定义pre,因为当前状态的cur[j]保存的便是dp[i-1][j]
每次从头开始更新cur[j-1]每次会变成dp[i][j-1],
所以直接往上累加即可
*/


class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n){
            return uniquePaths(n,m);
        }
        vector<int> cur(m,1);
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                cur[j]+=cur[j-1];
            }
        }
        return cur[m-1];
    }
};