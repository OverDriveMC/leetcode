/**
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
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
        q.push(make_pair(0,0));
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
			/**
			因为可能没有访问到这个节点,所以vis[][]可能还是为0,会重复添加很多次
			*/
            if(!judge(p.first,p.second, threshold) || vis[p.first][p.second] ){
                continue;
            }
            cnt++;
            cout<<p.first<<"  "<<p.second<<endl;
            vis[p.first][p.second]=1;
            for(int i=0;i<4;i++){
                int dx=p.first+dirs[i][0];
                int dy=p.second+dirs[i][1];
                if( dx<0 || dy<0 || dx>=rows || dy>=cols || vis[dx][dy] ){
                    continue;
                }
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
