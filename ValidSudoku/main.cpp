#include<bits/stdc++.h>
using namespace std;
/**
*行、列、九宫格 不重复即可
*/
class Solution {
public:
    static const int  SIZE=9;
    bool row[SIZE],column[SIZE][SIZE],grid[SIZE][SIZE];
    bool isValidSudoku(vector<vector<char> >& board) {
        init();
        for(int i=0; i<SIZE; i++) {
            memset(row,0,sizeof(row));
            for(int j=0; j<SIZE; j++) {
                if(board[i][j]!='.') {
                    int num=board[i][j]-'0'-1;
                /**
                *注意列 是每次 column[j][置位相应数字]
                *每个九宫格从左到右标号,第一行0  1 2  [0 1 2]/3*3+[0 1 2]/3
                *第一行的为0 1 2,第3行开始是3 4 5
                */
                    if(!row[num] && !column[j][num]
                            && !grid[i/3*3+j/3][num] ) {
                        row[num]=true;
                        column[j][num]=true;
                        grid[i/3*3+j/3][num]=true;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void init() {
        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));
        memset(grid,0,sizeof(grid));
    }
};

int main() {
    return 0;
}
