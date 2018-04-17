/**
K步从(0,0)跳到(X,Y)的方式



dp[i][a][b]表示i次移动后，马位于坐标(a，b)的情况数。
考虑下一步的八种移动方式对应的8个坐标分别为(a1，b1)...(a8，b8)，则状态转移方程如下：
dp[i+1][a1][b1] += dp[i][a][b]
dp[i+1][a2][b2] += dp[i][a][b]
...
dp[i+1][a8][b8] += dp[i][a][b]
初始状态为除了dp[0][0][0] = 1，其余都为0。答案就是dp[K][X][Y]。

时间复杂度
O(81*K)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int mod=1000000007;
LL dp[100005][10][10];
int dirs[8][2]={{-2,-1},{-1,-2},{1,2},{2,1},{-2,1},{2,-1},{1,-2},{-1,2}  };
int main()
{
    freopen("1.txt","r",stdin);
    int K,X,Y;
    scanf("%d%d%d",&K,&X,&Y);
    dp[0][0][0]=1;
    for(int k=1;k<=K;k++){
        for(int x=0;x<=8;x++){
            for(int y=0;y<=8;y++){
                for(int d=0;d<8;d++){
                    int tx=x+dirs[d][0];
                    int ty=y+dirs[d][1];
                    if(tx<=8 && tx>=0 && ty<=8 && ty>=0){
                        dp[k][tx][ty]= (dp[k][tx][ty] + dp[k-1][x][y])%mod;
                    }
                }
            }
        }
    }
    cout<<dp[K][X][Y]<<endl;
    return 0;
}
