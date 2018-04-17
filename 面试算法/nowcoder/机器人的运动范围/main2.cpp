class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows==0 || cols==0  ){
            return 0;
        }
        queue<pair<int,int>>q;
        int cnt=0;
        bool vis[rows][cols];
        memset(vis,0,sizeof(vis));
        if(judge(0,0,threshold)){
            q.push(make_pair(0,0));
            vis[0][0]=1;
        }
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            cnt++;
            for(int i=0;i<4;i++){
                int dx=p.first+dirs[i][0];
                int dy=p.second+dirs[i][1];
				//直接一次全判断完全
                if( dx<0 || dy<0 || dx>=rows || dy>=cols || vis[dx][dy] || !judge(dx,dy,threshold) ){
                    continue;
                }
                vis[dx][dy]=1;
                q.push(make_pair(dx,dy) );
            }
        }
        return cnt;
    }
    bool judge(int x,int y,int threshold){
        int sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }
        while(y){
            sum+=y%10;
            y/=10;
        }
        return sum<=threshold;
    }
private:
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1} };
};
