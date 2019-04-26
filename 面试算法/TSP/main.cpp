#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxn=1e5+5;
struct Edge{
    int from,to;
    LL val;
    int next;
}edges[1000005];
int head[maxn],edgenum,degree[maxn];
int before[maxn];
LL dp[maxn];
void addEdge(int from,int to, LL val){
    Edge edge={from,to,val,head[from]};
    edges[edgenum]=edge;
    head[from]=edgenum++;
}
int n,m;


class MyQueue{
public:
    bool empty(){
        return front==rear;
    }
    int top(){
        return arr[front];
    }
    int push(int val){
        arr[rear]=val;
        rear=(rear+1)%maxn;
    }
    void pop(){
        front=(front+1)%maxn;
    }
private:
    int arr[maxn];
    int front=0,rear=0;
};


/*
void print(int index){
    if(index==-1){
        return ;
    }
    print(before[index]);
    printf("%d ",index);
}
*/
#define SUBMIT

int main()
{
#ifndef SUBMIT
    freopen("1.txt","r",stdin);
#endif // SUBMIT
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    memset(degree,0,sizeof(degree));
    memset(dp,0,sizeof(dp));
    memset(before,-1,sizeof(before));
    int from,to;
    LL val;
    for(int i=0;i<m;i++){
        scanf("%d%d%lld",&to,&from,&val);
        addEdge(from,to,val);
        degree[to]++;
    }
#ifndef SUBMIT
    for(int i=0;i<edgenum;i++){
        cout<<edges[i].from<<"  "<<edges[i].to<<"  "<<edges[i].val<<endl;
    }
#endif // SUBMIT

    MyQueue queue;
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            //cout<<i<<endl;
            queue.push(i);
        }
    }
    while(!queue.empty()){
        int id=queue.top();
#ifndef SUBMIT
        cout<<"id:"<<id<<endl;
#endif

        queue.pop();
        for(int i=head[id]; ~i ;i=edges[i].next){
            int to=edges[i].to;
            if(dp[id]+edges[i].val> dp[to]){
                dp[to]=dp[id]+edges[i].val;
                before[to]=id;
            }
            if( (dp[id]+edges[i].val== dp[to]) && (before[to]>id ) ){
                before[to]=id;
            }
            degree[to]--;
            if(degree[to]==0){
                queue.push(to);
            }
        }
    }
    LL maxprofit=dp[1];
    int maxIndex=1;
    for(int i=2;i<=n;i++){
        if(dp[i]>maxprofit){
            maxprofit=dp[i];
            maxIndex=i;
        }
    }
    //printf("maxprofit:%lld\n",maxprofit);
    while(maxIndex!=-1){
        printf("%d ",maxIndex);
        maxIndex=before[maxIndex];
    }
    printf("\n");


    return 0;
}
