class Trie {
public:
    Trie** nodes;
    bool flag=false;
    /** Initialize your data structure here. */
    Trie() {
        nodes=new Trie*[26];
        for(int i=0;i<26;i++){
            nodes[i]=NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur=this;
        for(int i=0;i<word.size();i++){
            if(cur->nodes[word[i]-'a' ]==NULL){
                cur->nodes[word[i]-'a' ]=new Trie();
            }
            cur=cur->nodes[word[i]-'a' ];
        }
        cur->flag=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur=this;
        for(int i=0;i<word.size();i++){
            if(cur->nodes[word[i]-'a' ]!=NULL){
                cur=cur->nodes[word[i]-'a' ];
            }else{
                return false;
            }
        }
        return cur==NULL || cur->flag==true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie*cur=this;
        for(int i=0;i<prefix.size();i++){
            if(cur->nodes[prefix[i]-'a']==NULL){
                return false;
            }
            cur=cur->nodes[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */