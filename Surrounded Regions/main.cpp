class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0){
            return ;
        }
        int row=board.size();
        int column=board[0].size();
		/**
		*先将所有的边界上为O的并且与边界O相连的O置为1
		*/
        for(int i=0;i<row;i++){
            check(board, i,0, row,column);
            if(column>1){
                check(board, i,column-1, row,column);
            }
        }
        for(int i=0;i<column;i++){
            check(board,0,i,row,column);
            if(row>1){
                check(board,row-1 ,i,row,column);
            }
        }
		/**
		*接着把所有的O变成X
		*再将所有的1置为O
		*/
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }
            }
        }
    }
    int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1} };
    bool valid(const vector<vector<char>>&board,int tx,int ty,int row,int column){
        if(tx<0 || tx>=row || ty<0 || ty>=column || board[tx][ty]!='O' ){
            return false;
        }
        return true;
    }
    
    void check(vector<vector<char>>&board, int x,int y,int row,int column){
        if(board[x][y]=='O'){
            board[x][y]='1';
            for(int i=0;i<4;i++){
                int tx=x+dirs[i][0];
                int ty=y+dirs[i][1];
                if(valid(board,tx,ty,row,column)){
                    check(board,tx,ty,row,column);
                }
            }
        }
    }
};