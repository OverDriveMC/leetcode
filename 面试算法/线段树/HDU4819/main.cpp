#include <bits/stdc++.h>

using namespace std;

int T,n,Q;
const int maxn=805;
int Maxn[maxn<<2][maxn<<2],Minn[maxn<<2][maxn<<2];


void pushUp(int d,int o){
    Maxn[d][o]=max(Maxn[d][o<<1],Maxn[d][o<<1|1]);
    Minn[d][o]=min(Minn[d][o<<1],Minn[d][o<<1|1]);
}

void ybuild(int d, int o, int l, int r,bool flag){
    if(l==r){
        if(flag){
            scanf("%d",&Maxn[d][o]);
            Minn[d][o]=Maxn[d][o];
        }else{
            Maxn[d][o]=max(Maxn[d<<1][o],Maxn[d<<1|1][o]);
            Minn[d][o]=min(Minn[d<<1][o],Minn[d<<1|1][o]);
        }
    }else{
        int mid=(l+r)>>1;
        ybuild(d,o<<1,l,mid,flag);
        ybuild(d,o<<1|1,mid+1,r,flag);
        pushUp(d,o);
    }
}
void xbuild(int o,int l,int r){
    if(l==r){
        ybuild(o,1,1,n,true);
    }else{
        int mid=(l+r)>>1;
        xbuild(o<<1,l,mid);
        xbuild(o<<1|1,mid+1,r);
        ybuild(o,1,1,n,false);
    }
}
int xL,yL,xR,yR,val;
void modify_y(int d,int o,int l,int r,bool flag){
    if(l==r){
        if(flag){
            Maxn[d][o]=Minn[d][o]=val;
        }else{
            Maxn[d][o]=max(Maxn[d<<1][o],Maxn[d<<1|1][o]);
            Minn[d][o]=min(Minn[d<<1][o],Minn[d<<1|1][o]);
        }
    }else{
        int mid=(l+r)>>1;
        if(mid>=yL){
            modify_y(d,o<<1,l,mid,flag);
        }else{
            modify_y(d,o<<1|1,mid+1,r,flag);
        }
        pushUp(d,o);
    }
}
void modify_x(int o,int l,int r){
    if(l==r){
        modify_y(o,1,1,n,true);
    }else{
        int mid=(l+r)>>1;
        if(mid>=xL){
            modify_x(o<<1,l,mid);
        }else{
            modify_x(o<<1|1,mid+1,r);
        }
        modify_y(o,1,1,n,false);
    }
}
int minv,maxv;
void query_y(int d,int o,int l,int r){
    //cout<<d<<"  "<<o<<"  "<<Maxn[d][o]<<"  "<<Minn[d][o]<<endl;
    if(yL <=l && r <=yR){
        maxv=max(Maxn[d][o],maxv);
        minv=min(Minn[d][o],minv);
        return ;
    }
    int mid=(l+r)>>1;
    if(mid>=yL){
        query_y(d,o<<1,l,mid);
    }
    if(mid<yR){
        query_y(d,o<<1|1,mid+1,r);
    }
}
void query_x(int o,int l,int r){
    if(xL <=l && r<=xR){
        query_y(o,1,1,n);
    }else{
        int mid=(l+r)>>1;
        if(mid>=xL){
            query_x(o<<1,l,mid);
        }
        if(mid<xR){
            query_x(o<<1|1,mid+1,r);
        }
    }
}

int x,y,dis;
int cnt=1;
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("Case #%d:\n",cnt);
        cnt++;
        xbuild(1,1,n);
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%d%d%d",&x,&y,&dis);
            minv=1<<30;
            maxv=-(1<<30);

            xL=x-dis/2;
            xR=x+dis/2;
            yL=y-dis/2;
            yR=y+dis/2;
            //printf("%d %d %d %d\n",xL,xR,yL,yR);
            query_x(1,1,n);
            val=(maxv+minv)/2;
            printf("%d\n",val);
            xL=x;
            yL=y;
            modify_x(1,1,n);
        }
    }
    return 0;
}
