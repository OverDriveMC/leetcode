#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int row,column,grid;
    bool isValidSudoku(vector<vector<char> >& board) {
        for(int i=0;i<9;i++){
            init();
            for(int j=0;j<9;j++){
                if(!checkValid(row,board[i][j])
                   || !checkValid(column,board[j][i])
                   || !checkValid(grid,board[i/3*3+j/3][i%3*3+j%3])){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkValid(int &val,char c){
        if(c=='.'){
            return true;
        }
        int num=1<<(c-'0');
        if(val&num){
            return false;
        }
        val = val | num;
        return true;
    }
    void init(){
        row=0;
        column=0;
        grid=0;
    }
};

int main(){

}

