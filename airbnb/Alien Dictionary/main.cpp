#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        map<char,set<char> >edges;
        map<char,int>degree;
        buildGraph(words, edges,degree);
        string res=topoSort(words,edges,degree);

        return res;
    }
    string topoSort(vector<string>&words, map<char,set<char> >&edges,map<char,int>&degree){
        int cnt=degree.size();
        vector<char>res;
        while(res.size()<cnt){
            for(map<char,int>::iterator iter=degree.begin();iter!=degree.end();iter++){
                if(iter->second==0){
                    res.push_back(iter->first);
                    set<char>to=edges[iter->first ];
                    for(set<char>::iterator iter=to.begin(); iter!=to.end();iter++){

                        degree[*iter]--;
                    }
                    degree.erase(iter);
                    break;
                }
            }
        }

        set<char>charac;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(find(res.begin(),res.end(),words[i][j])==res.end() )
                    charac.insert(words[i][j]);
            }
        }

        //sort(charac.begin(),charac.end());
        string tt=string(charac.begin(),charac.end());
        sort(tt.begin(),tt.end());

        return string(res.begin(),res.end())+tt ;
    }

    void buildGraph(vector<string>&words, map<char,set<char> >&edges,map<char,int>&degree){
        set<string>vis;
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int length=min(w1.length(),w2.length());
            for(int j=0;j<length;j++){
                if(w1[j]==w2[j]){
                    continue;
                }
                vector<char>temp;
                temp.push_back(w1[j]);
                temp.push_back(w2[j]);
                string edge=string(temp.begin(),temp.end());
                if(vis.find(edge)==vis.end()){
                    if(degree.find(w1[j])==degree.end()){
                        degree[w1[j] ]=0;
                    }
                    edges[w1[j] ].insert(w2[j]);
                    degree[w2[j] ]++;
                }
                break;
            }
        }
    }

};

int main(){
    //["wrt","wrf","er","ett","rftt"]
    vector<string>words;
    words.push_back("wrt");
    words.push_back("wrf");
    words.push_back("er");
    words.push_back("ett");
    words.push_back("rftt");
    Solution s;
    string res=s.alienOrder(words);
    cout<<res<<endl;


    words.clear();
    words.push_back("zy");
    words.push_back("zx");

    res=s.alienOrder(words);
    cout<<res<<endl;
    return 0;
}
