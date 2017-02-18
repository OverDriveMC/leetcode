#include<bits/stdc++.h>

using namespace std;
/**
*方向考虑,节省空间
*从位置找矩阵中的元素
*在检测行是否合法时，i 表示矩阵的行，j 表示矩阵的列；
*检测列是否合法时，i 表示矩阵的列，j 表示矩阵的行；
*检测九宫格是否合法时，i 表示九宫格的标号，j 表示九宫格里的每个元素
*(只是我们需要根据i、j定位相应的元素到原来的矩阵：
*   第i个九宫格里面的第j个元素在原矩阵的第3*(i/3)+j/3行,
*   第3*(i%3)+j%3列,"/" 表示整数除法)
*/
class Solution {
public:
    bool row[9],column[9],grid[9];
    bool isValidSudoku(vector<vector<char> >& board) {
        for(int i=0;i<9;i++){
            init();
            for(int j=0;j<9;j++){
                ///row：i 行 j 列  board[i][j]
                ///column:i 列 j 行 board[j][i]
                ///grid：第i个  board[i/3*3+j/3][i%3*3+j%3]
                if(!checkValid(row,board[i][j])
                   || !checkValid(column,board[j][i])
                   || !checkValid(grid,board[i/3*3+j/3][i%3*3+j%3]) ){
                    return false;
                }
            }
        }
        return true;
    }


    bool checkValid(bool vis[],char val){
        if(val=='.'){
            return true;
        }
        int num=val-'0'-1;;
        if(!vis[num]){
            vis[num]=true;
            return true;
        }else{
            return false;
        }
    }
    void init(){
        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));
        memset(grid,0,sizeof(grid));
    }
};

int main(){
    Solution s;
    s.test();
    return 0;
}



