#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=20010;
struct Edge{
	int from,to,next;
}edge[maxn<<1];
int head[maxn],edgenum;
/**
将所有以结点为k的边做成链表
head[k]:代表第一条边的下标
head[k].next:代表第二条边的下标
直到最后一条边等于-1
*/
void addedge(int from, int to){
	Edge e={from,to,head[from]};
	edge[edgenum]=e;
	head[from]=edgenum++;
}

int T;
int N;
int dp[maxn],num[maxn];

void dfs(int cur,int parent){
	num[cur]=1;
/**
~ 代表取反,包括符号位
-1 ： 在计算机中表示为  FFFFFFFF(补码)
原码为: 80000001   
反码为: FFFFFFFE  然后+1 ====>补码 FFFFFFFF
取反即得到 0
*/
	for(int i=head[cur]; ~i ; i=edge[i].next){
		int to=edge[i].to;
		if(to!=parent){
			dfs(to,cur);
			dp[cur]=max(dp[cur], num[to]);
			num[cur]+=num[to];
		}
	}
	dp[cur]=max(dp[cur],N-num[cur]);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int from,to;
		memset(dp,-1,sizeof(dp));
		memset(head,-1,sizeof(head));
		edgenum=0;
		for(int i=1;i<N;i++){
			scanf("%d%d",&from,&to);
			addedge(from,to);
			addedge(to,from);
		}
		dfs(1,-1);
		int ans=dp[1];
		int index=1;
		for(int i=2;i<=N;i++){
			if(ans>dp[i]){
				ans=dp[i];
				index=i;
			}
		}
		printf("%d %d\n",index,ans);
	}
	return 0;
}
