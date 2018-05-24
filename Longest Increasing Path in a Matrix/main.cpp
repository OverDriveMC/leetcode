/**
在一个二维矩阵里面,找到最长上升路径
Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
步骤：
1.对每个cell进行DFS
2.只选择四个方向中比当前cell中值的方向走
3.最大的路径也是每个cell的最大的路径
4.通过判断matrix[dx][dy]>matrix[x][y]确保不会走重复路径
5.通过cache进行记忆化搜索,因为可能会重新遍历到一个路径
时间复杂度O(MN)
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0 || matrix[0].size()==0){
            return 0;
        }
        int n=matrix[0].size();
        vector<vector<int>>cache(m,vector<int>(n,0));
        int maxn=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxn=max(maxn,search(matrix,i,j,m,n,cache));
                //cout<<i<<"  "<<j<<"  "<<cache[i][j]<<endl;
            }
        }
        return maxn;
    }
    int search(vector<vector<int>>&matrix, int x,int y, int m,int n, vector<vector<int>>&cache){
        if(cache[x][y]!=0){
            return cache[x][y];
        }
        int maxn=1;
        for(int i=0;i<4;i++){
            int dx=x+dirs[i][0];
            int dy=y+dirs[i][1];
			//因为是最长上升路径,所以通过matrix[dx][dy]>matrix[x][y]确保不会走重复的结点
			//假如是最长不下降路径,则需要定义vis记录走过的结点
            if(dx>=0 && dx<m && dy>=0 && dy<n   && matrix[dx][dy]>matrix[x][y] ){
                maxn= max(maxn,  search(matrix,dx,dy,m,n, cache) +1 );
            }
        }
		//假如四个方向都不能走,cache要记为1
        cache[x][y]=maxn;
        return maxn;
        
    }
private:
    int dirs[4][2]={ {-1,0},{1,0},{0,1},{0,-1}};
};