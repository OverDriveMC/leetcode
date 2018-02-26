class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        int path=0;
        unordered_set<string>wdict(wordList.begin(),wordList.end());
        while(!q.empty()){
            int cnt=q.size();
            path++;
            for(int i=0;i<cnt;i++){
                string cur=q.front();
                q.pop();
                if(cur==endWord){
                    return path;
                }
                addToQueue(cur,wdict,q);
            }
        }
        return 0;
    }
    
    void addToQueue(string word, unordered_set<string>&wordList, queue<string>&q){
        wordList.erase(word);
        for(int i=0;i<word.size();i++){
            int temp=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(wordList.find(word)!=wordList.end()){
                    q.push(word);
                    wordList.erase(word);
                }
            }
            word[i]=temp;
        }
    }
};