class  UnionSet{
public:
    UnionSet(int size){
        parent.resize(size);
        nodes.resize(size);
        for(int i=0;i<size;i++){
            parent[i]=i;
            nodes[i]=1;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    bool unions(int x, int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return 1;
        }else if(nodes[px] >=nodes[py] ){
            parent[py]=px;
            nodes[px]+=nodes[py];
        }else{
            parent[px]=py;
            nodes[py]+=nodes[px];
        }
		/**
		假如两个不同集合合并了,那么岛屿数量-1
		*/
        count--;
        return 0;
    }
	/**
	采用并查集记录下1的数量
	*/
    int count=0;
private:
    vector<int>parent;
    vector<int>nodes;
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size()==0 ){
            return 0;
        }
        int m=grid.size();
        int n=grid[0].size();
        UnionSet us=UnionSet(m*n);
        for(int i=0;i<m ;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0'){
                    continue;
                }else{
                    us.count++;
                }
                int p=i*n+j;
/*
[["1","1","1"],["0","1","0"],["1","1","1"]]
所有位置都要遍历
*/
				
                if(i-1>=0 && grid[i-1][j]=='1'){
                   int q=(i-1)*n+j;
                   us.unions(p,q);
                }
                if(j-1>=0 && grid[i][j-1]=='1'){
                    int q=p-1;
                    us.unions(p,q);
                }
                if(i+1<m && grid[i+1][j]=='1'){
                    int q=(i+1)*n+j;
                    us.unions(p,q);
                }
                if(j+1<n && grid[i][j+1]=='1'){
                    int q=p+1;
                    us.unions(p,q);
                }
            }
        }
        return us.count;
        
    }
};