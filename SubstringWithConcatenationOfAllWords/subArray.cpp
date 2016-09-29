#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        int n=s.size();
        int nword=words.size();
        if(nword==0){
            return res;
        }
        int len=words[0].size();
        unordered_map<string,int>wordMap;
        ///将不同字符串插入到Map
        ///value为第1次出现时去掉重复串的index
        for(int i=0,index=0;i<nword;i++){
            if(wordMap.find(words[i])==wordMap.end()){
                wordMap.emplace(words[i],index++);
            }
        }
        int nwordMap=wordMap.size();
        ///index代表第index个字符串，记录出现的次数
        vector<int>wordCount(nwordMap,0);
        for(int i=0;i<nword;i++){
            wordCount[wordMap[words[i]]]++;
        }
        ///将s中的字符串映射到int数组里
        ///值为字符串在wordMap中的value，也即字符串的唯一标识
        vector<int>occur(n,-1);
        /**
        *注意size_t类型的隐式转换，假如这里使用s.size()
        *那么s.size()-len小于0的话会强转成一个很大的数
        */
        for(int i=0;i<=n-len;i++){
//            cout<<"i:"<<i<<endl;
            string word=s.substr(i,len);
            if(wordMap.find(word)!=wordMap.end()){
                occur[i]=wordMap[word];
            }
        }

        for(int i=0;i<len;i++){
            ///记录当前匹配成功的字符串数量
            int currentLength=0;
            ///初始化当前每个字符串出现的次数为0
            ///下标对应第index个字符串出现的次数
            vector<int>currentCount(nwordMap);
            for(int j=i;j<n;j+=len){
                int index=occur[j];
//                cout<<j<<"  "<<index<<endl;
                ///获取当前字符串的index，假如index小于0
                ///说明不是words里面的单词
                if(index>=0){
                    if(currentCount[index]<wordCount[index]){
                        currentLength++;
                        currentCount[index]++;
                    }else{
                        ///说明第index个单词匹配超过了限度
                        ///开始从头删除已经匹配的单词，直到找到第一个
                        ///下标也是index匹配的位置，因为当前匹配的index
                        ///没有对currentLength和currentCount造成影响，所以
                        ///匹配到index就结束，只需要把它之前的匹配的都-1即可
                        while(occur[j-(currentLength)*len]!=index){
                            ///注意occur，才是取index
                            --currentCount[occur[j-(currentLength)*len]];
//                            cout<<"pos:"<<j-(currentLength)*len<<endl;
//                            cout<<"j:"<<j<<"  "<<currentLength<<"  "<<currentCount[j-(currentLength)*len]<<endl;
                            --currentLength;
                        }
                    }
                }else{
                    ///说明要重新匹配
                    currentLength=0;
                    memset(currentCount.data(),0,nwordMap*sizeof(int));
                }
                if(currentLength==nword){
                    ///现在的j是最后一个成功匹配的，所以-1
//                    cout<<"add:"<<(j-(currentLength-1)*len)<<endl;
                    res.push_back(j-(currentLength-1)*len);
                }
            }
        }
        return res;
    }
};
int main(){
    Solution s;

    vector<string>vec;
    vec.push_back("foo");
    vec.push_back("bar");
    vec.push_back("foo");
    vector<int>v=s.findSubstring("foofoobarfoobar",vec);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }
    cout<<endl;
    vec.clear();
    vec.push_back("mississippis");
    v=s.findSubstring("mississippi",vec);
    string t="mississippi";
    cout<<"(t.size()-vec[0].size()):"<<(t.size()-vec[0].size())<<endl;
    cout<<"(0==t.size()):"<<(0==t.size())<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";
    }
    cout<<endl;

    vec.push_back("mississippis");
    v=s.findSubstring("mississippi",vec);
    vec.clear();
    vec.push_back("bbd");
    vec.push_back("dcb");
    vec.push_back("dcd");
    v=s.findSubstring("cacaabaacccdaadcaabdcddbababbbddcbdcddcbbaacadaadbdcacdaadbbbbad",
                      vec);
    for(int i : v){
        cout<<i<<"  ";
    }
    cout<<endl;
    return 0;
}
