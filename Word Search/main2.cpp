class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word==""){
            return true;
        }
        if(board.size()==0 || board[0].size()==0){
            return false;
        }
        vector<vector<bool> >vis(board.size(), vector<bool>(board[0].size(),0 ) );
		///直接遍历每一个位置作为开始位置,内部BFS搜索
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(search(i,j,board,word, 0,vis)){
                    return true;
                }
            }
        }  
        return false;
    }
    bool search(int x,int y, vector<vector<char>>&board, string word, int pos, vector<vector<bool>>vis ){
        if(pos== word.size()){
            return true;
        }   
        if(x<0 || x>=board.size()  || y<0 || y>=board[0].size()  || vis[x][y]  ||  word[pos]!=board[x][y] ){
            return false;
        }
        vis[x][y]=1;
        if(search(x+1,y,board, word, pos+1,vis) ||
                search(x-1,y,board, word, pos+1,vis) ||
           search(x,y+1,board, word, pos+1,vis) ||
           search(x,y-1,board, word, pos+1,vis) 
          ){
            return true;
        }
            
            
        return false;
    }
    
    
};