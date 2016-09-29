#include<bits/stdc++.h>

using namespace std;
/**
*不回溯
*假如超出匹配的个数
*则删除第一个，然后补一个单词，记录超出的个数
*最后判定超出个数为0
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>vec;
        if(words.empty()){
            return vec;
        }
        if(s.size()==0 && words[0].size()==0){
            vec.push_back(0);
            return vec;
        }
        int len=words[0].size();
        int lastIndex=s.size()-len;
        int windowLength=len*words.size();
        int lastStartIndex=s.size()-windowLength;
        map<string,int>wordmap;
        for(int i=0;i<words.size();i++){
            ///假如不存在，会自动插入make_paire(words[i],0);
            wordmap[words[i]]++;
        }
        ///一定循环len次(第一次0 len 2*len)
        for(int i=0;i<len;i++){
            map<string,int>current;
            ///最后一个位置时start+windowLength=j+len
            ///并且cnt=0
            int start=i;
            ///cnt代表匹配的字符串超出的数量
            ///例如aaa出现3次，现在出现了4次，cnt=1;
            int cnt=0;
            for(int j=i;j<=lastIndex && start<=lastStartIndex;j+=len){
                string word=s.substr(j,len);
                ///说明字符串不存在
                if(wordmap.find(word)==wordmap.end()){
                    start=j+len;
                    cnt=0;
                    current.clear();
                }else{
                    ///说明当前窗口的数量正好等于words中所有字符串的长度
                    ///但是还没有成功，说明cnt>0，所以每次删除最开始的元素
                    ///然后然后再加一个元素，看是否能够正好消掉那个多余的元素
                    if(j==(start+windowLength)){
                        string word=s.substr(start,len);
                        ///删除掉第一个单词，开始位置向后移len个
                        start+=len;
                        if(current[word]>wordmap[word]){
                            cnt--;
                        }
                        current[word]--;
                    }
                    int amount=++current[word];
                    if(amount>wordmap[word]){
                        cnt++;
                    }
                    if(cnt==0 && (start+windowLength)==(j+len)){
                        vec.push_back(start);
                    }
                }
            }
        }
        return vec;
    }

};

int main(){
    Solution s;
    vector<string>vec;
    vec.push_back("bar");
    vec.push_back("foo");
    vector<int>v=s.findSubstring("barfoothefoobarman",vec);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}
