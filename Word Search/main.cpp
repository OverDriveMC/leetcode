
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int x,y;
    Node(int x,int y):x(x),y(y){}
};

class Solution {
public:
    int dirs[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int res=INT_MAX;

    bool isValid(int x,int y,int max_x,int max_y){
        if(x<0 || x>=max_x || y<0 || y>=max_y){
            return false;
        }
        return true;
    }

    bool bfs(Node node, vector<vector<char>>& board, string& word,int pos,vector<vector<int> > cvis){
		///注意边界条件
        if(pos==word.size()-1){
            return board[node.x][node.y]==word[pos];
        }
        if(board[node.x][node.y]==word[pos]){
            cvis[node.x][node.y]=1;
            for(int i=0;i<4;i++){
                int x=node.x+dirs[i][0];
                int y=node.y+dirs[i][1];
                if(isValid(x,y , board.size(), board[0].size()) && !cvis[x][y] &&  bfs(Node(x,y) , board, word, pos+1,cvis) ){
                    return true;
                }
            }

        }
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word==""){
            return true;
        }
        if(board.size()== 0 || board[0].size()==0){
            return false;
        }

        bool vis[board.size()][board[0].size()];
        memset(vis,0,sizeof(vis));
        queue<Node>q;
        q.push(Node(0,0));
        while(!q.empty()){
            Node node=q.front();
            q.pop();
            if(vis[node.x][node.y]){
                continue;
            }
			/**
			* vis标记以x,y作为开始找的位置是否已经找过
			*/
            vis[node.x][node.y]=1;
            vector<vector<int> >cvis(board.size(), vector<int>(board[0].size(),0));
			/**
			*  cvis标记内部结点是否访问
			*/
            if(bfs(node,board,word,0,cvis)){
                return true;
            }
            for(int i=0;i<4;i++){
                int x=node.x+dirs[i][0];
                int y=node.y+dirs[i][1];
                if(isValid(x,y,board.size(),board[0].size())  && !vis[x][y]){
                    q.push(Node(x,y));
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<char> >vecs;
    vector<char>vec;
    vec.push_back('A');
    vec.push_back('B');
    vec.push_back('C');
    vec.push_back('E');
    vecs.push_back(vec);

    vector<char>vec2;
    vec2.push_back('S');
    vec2.push_back('F');
    vec2.push_back('C');
    vec2.push_back('S');
    vecs.push_back(vec2);

    vector<char>vec3;
    vec3.push_back('A');
    vec3.push_back('D');
    vec3.push_back('E');
    vec3.push_back('E');
    vecs.push_back(vec3);

    cout<<s.exist(vecs,"SEE")<<endl<<endl<<endl;
    cout<<s.exist(vecs,"ABCCED")<<endl<<endl<<endl;
    cout<<s.exist(vecs,"ABCB")<<endl;
    return 0;
}

