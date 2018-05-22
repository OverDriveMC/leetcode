/**
https://www.lintcode.com/problem/number-of-distinct-islands/description
计算不同岛屿的数量
相同的岛屿通过平移可以完全重合,但是不能通过旋转
通过记录相对位置坐标来判断,使用最左上角的1当做基点
Example
Given grid = 
[
[1,1,0,0,0],
[1,1,0,0,0],
[0,0,0,1,1],
[0,0,0,1,1]
]
return 1
Given grid = 
[
[1,1,0,1,1],
[1,0,0,0,0],
[0,0,0,0,1],
[1,1,0,1,1]
]
return 3
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int numberofDistinctIslands(vector<vector<int>> &grid) {
		int m=grid.size();
		if(m==0 || grid[0].size()==0){
			return 0;
		}
		int n=grid[0].size();
		unordered_set<string>set;
		vector<vector<bool>>vis(m,vector<bool>(n,0));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]==1 && !vis[i][j]){
					vector<string>strs;
					search(grid,i,j,i,j,vis,strs);
					string t="";
					for(auto s:strs){
						t+=s;
					}
					set.insert(t);
				}
			}
		}
		return set.size();
    }
	void search(vector<vector<int> >& grid, int ox,int oy, int x, int y, vector<vector<bool> >&vis,vector<string>&strs){
		int m=grid.size(),n=grid[0].size();
		vis[x][y]=1;
		strs.push_back(to_string(x-ox)+"_"+to_string(y-oy));
		for(int i=0;i<4;i++){
			int dx=x+dirs[i][0];
			int dy=y+dirs[i][1];
			if(dx>=0 && dx<m && dy>=0 && dy<n && !vis[dx][dy] && grid[dx][dy]==1){
				search(grid,ox,oy,dx,dy,vis,strs);
			}
		}
		
	}
private:
	int dirs[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
};