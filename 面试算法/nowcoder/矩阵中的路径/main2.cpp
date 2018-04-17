#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vector<vector<int>>vis(rows,vector<int>(cols,0));
                if(search(matrix,rows,cols,i,j,str,0,vis ) ){
                    return true;
                }
            }
        }
        return false;
    }
    bool valid(int rows,int cols,int x,int y,vector<vector<int>>&vis){
        if(x<0 || x>=rows || y<0 || y>=cols || vis[x][y]==1){
            return false;
        }
        return true;
    }
	/*
	vis是二维指针传入的,所以如果失败了,最后要手动归零
	*/
    bool search(char*matrix, int rows,int cols, int x, int y, char*str, int pos,vector<vector<int>>&vis){
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
