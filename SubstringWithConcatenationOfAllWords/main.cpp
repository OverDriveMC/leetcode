#include<bits/stdc++.h>
using namespace std;
/**
*hint:
*words里面单词可能有重的，所以在map里要记录次数
*/
class Solution {
public:
    typedef unsigned long long LL;
    const int seed=31;
    const static int maxn=1e+5;
    LL hash[maxn],xp[maxn];
    map<LL,int> wordsmap;
    void getHashCode(string s){
        hash[s.size()]=0;
        for(int i=s.size()-1;i>=0;i--){
            hash[i]=hash[i+1]*seed+s[i];
        }
    }
    LL getHash(int start,int len){
        return hash[start]-hash[start+len]*xp[len];
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>vec;
        if(words.size()==0 || words[0].size()==0){
            return vec;
        }
        int endpos=s.size()-words[0].size()*words.size();
        if(endpos<0){
            return vec;
        }

        xp[0]=1;
        for(int i=1;i<maxn;i++){
            xp[i]=xp[i-1]*seed;
        }
        getHashCode(s);
        for(int i=0;i<words.size();i++){
            LL hashcode=0;
            for(int j=words[i].size()-1;j>=0;j--){
                hashcode=hashcode*seed+words[i][j];
            }

            if(wordsmap.find(hashcode)==wordsmap.end()){
                wordsmap.insert(make_pair(hashcode,1));
            }else{
                wordsmap[hashcode]++;
            }
        }
//        for(map<LL,int>::iterator iter=wordsmap.begin();
//                    iter!=wordsmap.end();++iter){
//            cout<<iter->first<<"  "<<iter->second<<endl;
//        }

        for(int i=0;i<=endpos;i++){
            map<LL,int>t=wordsmap;
            for(int j=i;;j+=words[0].size()){
                LL hashcode=getHash(j,words[0].size());
                if(t.find(hashcode)!=t.end()){
                    int amount=t[hashcode];
                    amount--;
                    if(amount==0){
                        t.erase(hashcode);
                    }else{
                        t[hashcode]--;
                    }
                }else if(t.empty()){
                    vec.push_back(i);
                    break;
                }else{
                    break;
                }
            }
        }
        return vec;
    }


};
int main(){
    Solution s;
    vector<string> words;
    words.push_back("word");
    words.push_back("good");
    words.push_back("good");
    words.push_back("best");
    vector<int>vec=s.findSubstring("wordgoodgoodgoodbestword",words);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
