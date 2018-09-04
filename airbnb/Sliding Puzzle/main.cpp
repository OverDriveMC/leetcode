#include<bits/stdc++.h>

using namespace std;

struct Node{
    vector<vector<int>>state;
    string estate;
    int zx,zy;
    Node(vector<vector<int>>&state,int zx,int zy):state(state),zx(zx),zy(zy){}
};
class Solution {
public:
    int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1} };
    int slidingPuzzle(vector<vector<int>>& board) {
        string finalRes="123450";
        int res=0;
        queue<Node>q;
        unordered_set<string>vis;
        string state=encode(board);
        if(state==finalRes){
            return res;
        }
        int pos=state.find('0');
        q.push(Node(board,pos/3,pos%3));
        vis.insert(state);
        while(!q.empty()){
            res++;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node tmp=q.front();
                q.pop();
				/**
				BFS搜索,每次枚举完所有步数为res的情况,之后队列中新的情况,都是需要移动res+1次的情况
				*/
                for(int j=0;j<4;j++){
                    int tx=tmp.zx+dirs[j][0];
                    int ty=tmp.zy+dirs[j][1];
                    if(tx>=0 && tx<=1 && ty>=0 && ty<=2){
                        vector<vector<int>>newState=tmp.state;
                        swap(newState[tmp.zx][tmp.zy],newState[tx][ty] );
                        string nstate=encode(newState);
                        if(nstate==finalRes){
                            return res;
                        }
                        if(vis.find(nstate)==vis.end()){
                            vis.insert(nstate);
                            q.push(Node(newState,tx,ty ));
                        }
                    }
                }
            }
        }
        return -1;
    }
    string  encode(vector<vector<int>>&vec){
        stringstream os;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size();j++){
                os<<vec[i][j];
            }
        }
        return os.str();
    }
};


int main(){
    Solution s;
    vector<vector<int>> board;
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    board.push_back(v1);
    vector<int>v2;
    v2.push_back(5);
    v2.push_back(4);
    v2.push_back(0);
    board.push_back(v2);
    int res=s.slidingPuzzle(board);
    cout<<res<<endl;
    return 0;
}
