/**
树T有N个结点(1,...N),计算树的平衡度
balance:删除T中一个节点后剩下的树中最大的树的节点数
找到数的重心,如果有多个,返回最小的节点号
2 ——  1 —— 3
|	  |    |
6     4    7
	  |
      5
删除掉节点4之后,形成两棵树{5},{1,2,3,6,7},balance即为5
删除掉1后,形成3棵树{2,6},{3,7},{4,5},balance即为2
输入:
第一行样例数t,第二行N(1<=N<=20000),接下来的N-1行包含树的边
输出
返回最小balance的节点号以及balance
Sample Input
1
7
2 6
1 2
1 4
4 5
3 7
3 1
Sample Output
1 2
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=2e4+5;

int T,N;
vector<vector<int>>g(maxn,vector<int>());
//dp[i]表示删除掉节点i之后剩余的连通分量中节点数的最大值
//num表示去了父节点那个子树外的所有节点
int dp[maxn],num[maxn];

int dfs(int cur,int parent){
    if(dp[cur]!=-1){
        return dp[cur];
    }
    num[cur]=1;
    for(int i=0;i<g[cur].size();i++){
		//搜索去掉父节点之外的所有子树
        if(g[cur][i]!=parent){
			//开始搜索该子树的balance
            dfs(g[cur][i],cur);
			//为所有子树balance的最大值
			//num[g[cur][i]] :代表节点g[cur][i]除了父节点那条路径以外的所有节点的总数,这样便得到
			//父节点在g[cur][i]这条路径的所有节点数
            dp[cur]=max(dp[cur],num[g[cur][i] ]);
			//记录所有不经过父节点parent的节点总数
            num[cur]+=num[g[cur][i] ];
        }
    }
    /**
        因为父节点在上面会直接返回(continue)
        所以上面通过num统计除了父节点的那条路径的其余路径的节点数量
        然后用N- 其余节点的数目 ==  父节点的那条路径的节点数量
	*/
    dp[cur]=max(dp[cur],N-num[cur]);
    return dp[cur];
}

int main(){
    //freopen("1.txt","r",stdin);
    int from,to;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
		//初始化
        memset(dp,-1,sizeof(dp));
        memset(num,-1,sizeof(num));
        for(int i=1;i<=N;i++){
            g[i].clear();
        }
        for(int i=1;i<N;i++){
            scanf("%d%d",&from,&to);
			//建图
            g[from].push_back(to);
            g[to].push_back(from);
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
