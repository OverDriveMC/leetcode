#include<bits/stdc++.h>

using namespace std;
/**
不能仅仅检查duplicated-parent,例如
[[2,1],[3,1],[4,2],[1,4]]
got [3,1],但应该删除[2,1]
不能单独的考虑2种情况:duplicated-parents and cycle
应该检查3种不同情况:
1.no cycle, but there is one node who has 2 parents
[[1,2],[1,3],[2,3]] node 3 有两个parents ([1,3][2,3]),返回最后一次出现的[2,3]
2. A cycle, and there is one node who has 2 parents, that node must be inside the loop.
[[1,2],[2,3],[3,1],[4,1]] {1->2->3->4->1}是一个cycle,node 1有两个parents([4,1] [3,1])
返回the edge inside the loop, return [3,1]
3. A cycle, and every node has only 1 parent
[[1,2],[2,3],[3,1],[1,4]] {1->2->3->1} 是一个cycle,  可以删除任意在cycle中的边,
图依旧合法,返回最后一个出现的[3,1]
*/
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int> >& edges) {
        int MAX_EDGE_VAL=1005;
        vector<int>g[MAX_EDGE_VAL];
        ///DFS时,未访问的结点标记为0,正在访问的结点标记为1,访问完的结点标记为2
        ///假如访问的当前结点遇到标记为1的结点说明有环
        int vis[MAX_EDGE_VAL];
        vector<int>parent[MAX_EDGE_VAL];
        int node2parent=-1;
        for(int i=0;i<edges.size();i++){
            vector<int>edge=edges[i];
            parent[edge[1]].push_back(edge[0]);
            if(parent[edge[1]].size()>1){
                node2parent=edge[1];
            }
        }
        vector<int>lastCycleEdge;
        for(int i=0;i<edges.size();i++){
            memset(vis,0,sizeof(vis));
            if(dfs(g,edges[i][1],edges[i][0],vis)){
                lastCycleEdge=edges[i];
                break;
            }else{
                g[edges[i][0] ].push_back(edges[i][1]);
            }
        }
        if(node2parent==-1){
            ///情况3,只有环,每个节点只有一个父节点
            return lastCycleEdge;
        }else{
            if(lastCycleEdge.size()==0){
                ///情况1,没有环,有一个结点有2个父节点
                vector<int>res;
                res.push_back(parent[node2parent][1]);
                res.push_back(node2parent);
                return res;
            }else{
                ///情况2,有环,有一个结点有2个父节点
                int temp=node2parent;
                ///回溯,找出环,看两个父亲结点哪一个在环内
                ///找到在环内的父亲结点,环内某个结点的父亲一定过lastCycleEdge[1]
                while(parent[temp].size()>0 && parent[temp][0]!=lastCycleEdge[1]){
                    temp=parent[temp][0];
                    //cout<<temp<<"  "<<"   "<<parent[temp][0]<<"  "<<lastCycleEdge[1] <<endl;
                }
                vector<int>res;
                //cout<<parent[temp].size()<<"  "<<parent[node2parent][0]<<"  "<<parent[node2parent][1]<<endl;
                if(parent[temp].size()==0){
                    res.push_back(parent[node2parent][1]);
                }else{
                    res.push_back(parent[node2parent][0]);
                }
                res.push_back(node2parent);
                return res;
            }
        }

    }
    bool dfs(vector<int>*g,int from,int to,int *vis){
        vis[from]=1;
        for(int i=0;i<g[from].size();i++){
            if(vis[g[from][i] ]){
                continue;
            }
            if(g[from][i]==to){
                return true;
            }
            if(dfs(g,g[from][i],to,vis)){
                return true;
            }
        }
        return false;
    }

};

int main(){
    Solution s;
    vector<vector<int> >edges;
    vector<int>edge1;
    edge1.push_back(2);
    edge1.push_back(1);
    edges.push_back(edge1);
    vector<int>edge2;
    edge2.push_back(3);
    edge2.push_back(1);
    edges.push_back(edge2);
    vector<int>edge3;
    edge3.push_back(4);
    edge3.push_back(2);
    edges.push_back(edge3);
    vector<int>edge4;
    edge4.push_back(1);
    edge4.push_back(4);
    edges.push_back(edge4);
    vector<int>res=s.findRedundantDirectedConnection(edges);
    cout<<res[0]<<"  "<<res[1]<<endl;
}

