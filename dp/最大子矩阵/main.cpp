/**
给定一个m*n的整数矩阵,在上面找一个x*y
*/


#include<bits/stdc++.h>

using namespace std;
const int maxn=1005;

int T;
int m,n,x,y;
int arr[maxn][maxn];
int dp[maxn][maxn];

int main(){
    freopen("1.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		int maxn=-0x3f3f3f3f;
		scanf("%d%d%d%d",&m,&n,&x,&y);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&arr[i][j]);
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
				if(i>=x && j>=y){
					maxn=max(maxn, dp[i][j]-dp[i-x][j]-dp[i][j-y]+dp[i-x][j-y]);
				}
			}
		}
		printf("%d\n",maxn);
	}

}
