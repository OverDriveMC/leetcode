/**
题目大意：给一张地图，战列舰用X表示，空地用.表示，战列舰只可能横着或者竖着一条，而且两条战列舰之间肯定有空地，计算战列舰的个数～
Example:
X..X
...X
...X
In the above board there are 2 battleships.
找X的不相连的区域块个数
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()==0 ){
            return 0;
        }
        int res=0;
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
				//将访问过的标记为1
				if(!vis[i][j] && board[i][j]=='X'){
                    res++;
                    search(i,j , vis, board);
                }
            }
        }
        return res;
    }
    void search(int x,int y, vector<vector<bool>>&vis, vector<vector<char>>&board){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int dx=x+dirs[i][0];
            int dy=y+dirs[i][1];
            if(dx>=0 && dx<board.size() && dy>=0 && dy<board[0].size() && !vis[dx][dy] && board[dx][dy]=='X' ){
                search(dx,dy,vis, board);
            }
        }
    }
private:
    int dirs[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };
};


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()==0){
            return 0;
        }        
        int res=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
				//直接判断左边和上面是否为X即可
                if(board[i][j]=='X' && (i==0 || board[i-1][j]=='.') && (j==0 || board[i][j-1]=='.')){
                    res++;
                }
            }
        }
        return res;
    }
};