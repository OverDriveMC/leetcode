class Solution {
    public boolean exist(char[][] board, String word) {
        if(word.length()==0){
            return true;
        }
        if(board.length==0 || board[0].length==0){
            return false;
        }
        for(int i=0;i< board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(search(i,j, board, word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    public boolean search(int x, int y, char[][]board, String word, int pos){
        if(pos== word.length()){
            return true;
        }
        if(x<0 || x>=board.length || y<0 || y>=board[x].length || board[x][y]!=word.charAt(pos) ){
            return false;
        }
		///使用位运算,先将字母修改
		///也可以先-100 ,最后在 + 100
        board[x][y]^=256;
        if(search(x+1,y,board, word, pos+1) ||
           search(x-1,y,board, word, pos+1) ||
           search(x,y+1,board, word, pos+1) ||
           search(x,y-1,board, word, pos+1) 
          ){
            return true;
        }
		///最后将字母还原
        board[x][y]^=256;
        return false;
    }
}