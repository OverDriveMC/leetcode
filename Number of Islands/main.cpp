/**
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
所有相邻的1构成一个岛屿,计算有多少个岛屿
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0){
            return 0;
        }
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(),0));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
					/**
					直接采用搜索的方法,同时将邻近的1的vis全部标记为0
					*/
                    mark(grid,i,j,vis);
                }
            }
        }
        return cnt;
    }
    void mark(vector<vector<char>>&grid,int x,int y, vector<vector<bool>>&vis){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int dx=x+dirs[i][0];
            int dy=y+dirs[i][1];
            if(dx>=0 && dx<grid.size()  && dy>=0 && dy<grid[dx].size() && grid[dx][dy]=='1' && !vis[dx][dy] ){
                mark(grid, dx,dy, vis);
            }
            
        }
    }
private:
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1} };
};