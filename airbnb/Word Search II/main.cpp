struct TrieNode{
    string word="#";
	//建字典树这里要用二维指针
    struct TrieNode** node;
    TrieNode(){
        node=new TrieNode*[26];
        for(int i=0;i<26;i++){
            node[i]=nullptr;
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
		//先将所有的单词建立字典树
        for(int i=0;i<words.size();i++){
            buildTree(root,words[i]);
        }
        vector<string>res;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
				//然后枚举所有在字典树中的单词
                if(root->node[board[i][j]-'a']!=nullptr  ){
                    search(board, i,j, root->node[board[i][j]-'a'], res);
                }
            }
        }
        return res;
    }
    void search(vector<vector<char>>&board, int x,int y, TrieNode* root, vector<string>&res){
       // cout<<board[x][y]<<"  "<<root->word<<endl;
        if(root->word!="#"){
            /**
            这种需要去重
            [["a","a"]]
            ["a"]
            */
            res.push_back(root->word);
            root->word="#";
        }
        board[x][y]-=128;
        for(int i=0;i<4;i++){
            int dx=x+dirs[i][0];
            int dy=y+dirs[i][1];
			//假如能沿着字典树走,即字典树中出现了这个序列,那么接着遍历
            if(dx>=0&&dx<board.size() && dy>=0 && dy<board[dx].size() && board[dx][dy]>=0 && root->node[board[dx][dy]-'a']!=nullptr  ){
                search(board,dx,dy, root->node[board[dx][dy]-'a'],res);
            }
            
        }
        board[x][y]+=128;
    }
    
    
    void buildTree(TrieNode*root, string word){
        TrieNode* tmp=root;
        for(int i=0;i<word.size();i++){
            if(tmp->node[word[i]-'a']==nullptr){
                tmp->node[word[i]-'a']=new TrieNode();
            }
            tmp=tmp->node[word[i]-'a'];
        }
		//将带有单词的节点值设为该单词的值
        tmp->word=word;
    }
private:
    int dirs[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
};
