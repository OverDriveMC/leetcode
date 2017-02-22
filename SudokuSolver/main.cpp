#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>>& board,int row,int column){
        ///说明0-8行全部填充完毕,填写成功
        if(row==board.size()){
            return true;
        }
        ///说明当前列填充完毕,开始填充下一行
        if(column==board.size()){
            return dfs(board,row+1,0);
        }
        ///只有为.(即没有填充)的时候才需要试填
        if(board[row][column]!='.'){
            return dfs(board,row,column+1);
        }
        ///尝试在该(row,column)格填写1-9,假如成功,进入下一列
        for(char i='1';i<='9';i++){
            if(isValid(board,row,column,i)){
                ///设置该位置为指定字符
                board[row][column]=i;
                if(dfs(board,row,column+1)){
                    return true;
                }
            }
        }
        ///假如尝试了1-9填写的都不合法,那么置".",返回false,回溯
        board[row][column]='.';
        return false;
    }
    ///检查row行column列填入字符val是否会与已知矩阵冲突
    bool isValid(vector<vector<char>>& board,int row,int column,char val){
        ///检查行、列、是否合法
        for(int i=0;i<board.size();i++){
            if(board[row][i]==val || board[i][column]==val || board[row-row%3+i%3][column-column%3+i/3]==val){
                return false;
            }
        }
        return true;
    }
};


int main(){
    return 0;
}
