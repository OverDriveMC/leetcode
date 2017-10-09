#include<bits/stdc++.h>
using namespace std;

/*

dsu.find(node x):
	which outputs a unique id so that two nodes have the same id if and only if
	they are in the same connected component
dsu.union(node x,node y):
	which draws an edge (x,y) in the graph, connecting the components with id find(x) and
	find(y) together

To achieve this, keep track of parent, which remembers the id of a smaller node in the same connected
component, If the node is it's own parent, we call this the leader of that connected component.

use two techniques to improve the run-time complexity: path-compression and union-by-rank
	path compression involves changing the x=parent[x] in the find function to parent[x]=find(parent[x])
		Basically,as we compute the correct leader for x, we should remember our calculation.
	union-by-rank involves distributing the wordload of find across leaders evenly.Whenever we dsu.union(x,y)
		we have two leaders xr,yr and we have to choose whether we want parent[x]=yr or parent[y]=xr.
		we choose the leader that has a higher following to pick up a new follower.
		Specifically the meaning of rank if that there are less than 2^rank[x] followers of x. This strategy
		can be shown to give us better bounds for how long the recursive loop in dsu.find could run for.
*/

/**
Complexity Analysis
	Time Complexity: O(Nα(N))≈O(N), where N is the number of vertices (and also the number of edges) 
	in the graph, and α is the Inverse-Ackermann function. 
	We make up to N queries of dsu.union, which takes (amortized) O(α(N)) time. 
	Outside the scope of this article, it can be shown why dsu.union has O(α(N)) complexity, 
	what the Inverse-Ackermann function is, and why O(α(N)) is approximately O(1).

	Space Complexity: O(N). The current construction of the graph (embedded in our dsu structure) 
	has at most N nodes.



*/
class DSU{
public:
	int* parent;
	int *rank;

	DSU(int size){
		parent=new int[size+5];
		rank=new int[size+5];
		for(int i=0;i<=size;i++){
			parent[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		if(parent[x]!=x){
			///路径压缩,都更新为最顶的父节点
			parent[x]=find(parent[x]);
		}
		return parent[x];
	}
	bool Union(int x,int y){
		int xr=find(x);
		int yr=find(y);
		//cout<<x<<"  "<<xr<<"  "<<y<<"  "<<yr<<endl;
		if(xr==yr){
			return false;
		}
		if(rank[xr]>rank[yr]){
			parent[yr]=xr;
		}else if(rank[xr]<rank[yr]){
			parent[xr]=yr;
		}else{
			parent[yr]=xr;
			rank[xr]++;
		}
		return true;
	}
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
		int MAX_EDGE_SIZE=1000;
		DSU dsu(MAX_EDGE_SIZE);
		for(int i=0;i<edges.size();i++){
			vector<int>edge=edges[i];
			if(!dsu.Union(edge[0],edge[1]) ){
				return edge;
			}
		}
    }
};

int main(){
    Solution s;
    vector<vector<int> >edges;
    vector<int>edge1;
    edge1.push_back(1);
    edge1.push_back(5);
    edges.push_back(edge1);
    vector<int>edge2;
    edge2.push_back(3);
    edge2.push_back(4);
    edges.push_back(edge2);
    vector<int>edge3;
    edge3.push_back(3);
    edge3.push_back(5);
    edges.push_back(edge3);

    vector<int>edge4;
    edge4.push_back(4);
    edge4.push_back(5);
    edges.push_back(edge4);

    vector<int>edge5;
    edge5.push_back(2);
    edge5.push_back(4);
    edges.push_back(edge5);
    vector<int>res=s.findRedundantConnection(edges);
    cout<<res[0]<<"  "<<res[1]<<endl;
}


