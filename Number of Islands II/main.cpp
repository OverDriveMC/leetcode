/**
https://www.lintcode.com/problem/number-of-islands-ii/description
每次将一个点由海洋变为陆地,计算当前总共的岛屿个数


Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, 
the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and 
each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. 
Return how many island are there in the matrix after each operator.
Given n = 3, m = 3, array of pair A = [(0,0),(0,1),(2,2),(2,1)].

return [1,1,2,2].
*/

class DSU{
public:
	int*parent;
	int*rank;

	DSU(int size){
		parent=new int[size];
		rank=new int[size];
		for(int i=0;i<size;i++){
			parent[i]=i;
			rank[i]=1;
		}

	}

	int find(int x){
		if(parent[x]!=x){
			parent[x]=find(parent[x]);
		}
		return parent[x];
	}

	bool Union(int x,int y){
		/**
		这里一定要用find，，因为parent可能还没有更新为最新的
		*/
		int px=find(x);
		int py=find(y);
		if(px==py){
			return 1;
		}
		if(rank[px]>=rank[py]){
			parent[py]=px;
			rank[px]+=rank[py];
		}else{
			parent[px]=py;
			rank[py]+=rank[px];
		}
		return 0;
	}
};


class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<int>res;
		vector<vector<bool>> vis(n, vector<bool>(m,0));
		int cnt=0;
		DSU dsu=DSU(n*m);
		for(int i=0;i<operators.size();i++){
			Point p=operators[i];
			if(vis[p.x][p.y]){
				res.push_back(cnt);
				continue;
			}
			vis[p.x][p.y]=1;
			int pindex=p.x*m+p.y;
			//cnt每次出现1都要加1,然后假如可以合并在减去
			cnt++;
			for(int d=0;d<4;d++){
				int dx=p.x+dirs[d][0];
				int dy=p.y+dirs[d][1];
				if(dx>=0 && dy>=0 && dx<n && dy<m && vis[dx][dy]==1){
					int qindex=dx*m+dy;
					if(!dsu.Union(pindex,qindex)){
						cnt--;
					}
				}
			}
			res.push_back(cnt);
		}
		return res;
    }
private:
	int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1} };
};
