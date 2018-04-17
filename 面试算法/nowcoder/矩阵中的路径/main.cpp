/**
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如 
a b c e 
s f c s 
a d e e 
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void init(int**vis,int rows,int cols){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vis[i][j]=0;
            }
        }
    }
    void destroy(int**vis,int rows){
        for(int i=0;i<rows;i++){
            delete[]vis[i];
        }
        delete[]vis;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
		//创建二维数组
        int **vis=new int*[rows];
        for(int i=0;i<rows;i++){
            vis[i]=new int[cols];
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                init(vis,rows,cols);
                if(search(matrix,rows,cols,i,j,str,0,vis ) ){
                    destroy(vis,rows);
                    return true;
                }
            }
        }
        destroy(vis,rows);
        return false;
    }
    bool valid(int rows,int cols,int x,int y,int**vis){
        if(x<0 || x>=rows || y<0 || y>=cols || vis[x][y]==1){
            return false;
        }
        return true;
    }
	/*
	vis是二维指针传入的,所以如果失败了,最后要手动归零
	*/
    bool search(char*matrix, int rows,int cols, int x, int y, char*str, int pos,int **vis){
		//注意,因为这里是提前判的vis,所以截止条件不能用
		// str[pos]=='\0',因为所有的位置都访问过了,不会有valid的位置
        if(pos==strlen(str)-1  ){
            return str[pos]==matrix[x*cols+y ];
        }
        if(str[pos]!=matrix[x*cols+y ]){
            return false;
        }
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int dx=x+dirs[i][0];
            int dy=y+dirs[i][1];
            if(valid(rows,cols,dx,dy,vis ) ){
                if(search(matrix,rows,cols,dx,dy,str,pos+1,vis)){
                    return true;
                }
            }
        }
		//标记未访问
        vis[x][y]=0;
        return false;
    }



private:
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1} };
};

int main(){

    Solution s;
    char* matrix="AAAAAAAAAAAA";
    cout<<s.hasPath(matrix,3, 4, "AAAAAAAAAAAA")<<endl;
    return 0;
}
