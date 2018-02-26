class DSU{
public: 
	int* parent;
	int* rank;
	
	DSU(int size){
		parent=new int[size+5];
		rank=new int[size+5];
		for(int i=0;i<size+5;i++){
			parent[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		if(parent[x]!=x ){
			parent[x]=find(parent[x]);
		}
		//注意,这里返回parent[x]
		return parent[x];
	}
	bool connected(int x,int y){
		return find(x)==find(y);
	}
	bool Union(int x,int y){
		int xr=find(x);
		int yr=find(y);
		if(xr==yr){
			return false;
		}
		if(rank[xr]>rank[yr]){
			parent[yr]=xr;
		}else if(rank[xr]<rank[yr]){
			parent[xr]=yr;
		}else{
			parent[xr]=yr;
			rank[yr]++;
		}
		return true;
	}
	
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0){
			return ;
		}
		int row=board.size();
		int column=board[0].size();
		DSU dsu(row*column);
		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++){
				/**
				* 使用并查集,将所有的边缘部分连接到row*column上
				*/
				if( (i==0 || j==0 || (i==row-1) || (j==column-1) ) && board[i][j]=='O' ){
                    //cout<<i<<"  "<<j<<endl;
                    //cout<<dsu.parent[row*column]<<endl;
					dsu.Union(i*column+j, row*column);
				}else if(board[i][j]=='O'){
					/**
					* 假如当前位置是O的情况下,将当前位置 与 四周相连
					*/
					if(board[i-1][j]=='O'){
						dsu.Union(i*column+j, (i-1)*column+j );
					}
					if(board[i+1][j]=='O'){
						dsu.Union(i*column+j, (i+1)*column+j );
					}
					if(board[i][j-1]=='O'){
						dsu.Union(i*column+j, i*column+j-1 );
					}
					if(board[i][j+1]=='O'){
						dsu.Union(i*column+j, i*column+j+1 );
					}
				}
				
			}
		}
        
		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++){
                //cout<<dsu.parent[i*column+j]<<"   ";
				///如果是有row*column相连的话,说明与边缘位置相连,不需要修改为X
				if(!dsu.connected(i*column+j, column*row)){
					board[i][j]='X';
				}
			}
            //cout<<endl;
		}
    }
};