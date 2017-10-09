#include<bits/stdc++.h>

using namespace std;
/**
Time Complexity: O(N^2)
	where N is the number of vertices (and also the number of edges) in the graph. 
	In the worst case, for every edge we include, we have to search every 
	previously-occurring edge of the graph.

Space Complexity: O(N). 
	The current construction of the graph has at most N nodes.

*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
		const int MAX_EDGE_VAL=1005;
		vector<int>*g=new vector<int>[MAX_EDGE_VAL];
		bool vis[MAX_EDGE_VAL];
		for(int i=0;i<edges.size();i++){
			memset(vis,0,sizeof(vis));
			///每个边(u,v)加进来之前,先dfs判断一下是否u到v已经可达
			///假如已经可达,说明它是重复边
			if(dfs(g,edges[i][0],edges[i][1],vis )){
				return edges[i];
			}
			g[edges[i][0]].push_back(edges[i][1]);
			g[edges[i][1]].push_back(edges[i][0]);
		}
    }

	bool dfs(vector<int>*g,int from,int to,bool *vis){
		///标记访问
		vis[from]=1;
		for(int i=0;i<g[from].size();i++ ){
			///找到可达边
			if(g[from][i]==to){
				return true;
			}
			///是否可以通过邻边找到可达边
			if(!vis[g[from][i] ]){
				if(dfs(g,g[from][i],to,vis)){
					return true;
				}
			}
		}
		return false;
	}
};

int main(){
    Solution s;
    vector<vector<int> >edges;
    vector<int>edge1;
    edge1.push_back(1);
    edge1.push_back(2);
    edges.push_back(edge1);
    vector<int>edge2;
    edge2.push_back(1);
    edge2.push_back(3);
    edges.push_back(edge2);
    vector<int>edge3;
    edge3.push_back(2);
    edge3.push_back(3);
    edges.push_back(edge3);
    vector<int>res=s.findRedundantConnection(edges);
    cout<<res[0]<<"  "<<res[1]<<endl;
}

