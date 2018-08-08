#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        for(int i=0,k,l;i<words.size();i+=k){
            //每次添加k的单词,先判断第k个单词能否添加,然后再去添加第k个单词
            for(k=l=0;i+k<words.size() && l+words[i+k].size()+k<=maxWidth;k++){
                l+=words[i+k].size();
            }
            //这里不能写成ss(words[i])会有问题？？？？
            stringstream ss;
            ss<<words[i];
            for(int j=1;j<k;j++){
                int num=1;
                //要求最后一行每个单词之间只能相隔一个空格
                if(i+k<words.size()){
                    // 前 (L-l) % (k-1) 隔板之间需要一个额外的空格
                    num=(maxWidth-l)/(k-1) +(j<=((maxWidth-l)%(k-1)));
                }
                string blank=string(num,' '  );
                ss<<blank;
                ss<<words[i+j];
            }
            ss<<string(maxWidth- ss.str().size(),' ');
            res.push_back(ss.str());
        }
        return res;
    }
};



int main(){
    Solution s;
    string sa[]={"What","must","be","acknowledgment","shall","be"};
    vector<string> words(sa,sa+6);
    cout<<words.size()<<endl;
    vector<string>res=s.fullJustify( words, 16);
    for(auto s: res){
        cout<<s<<endl;
    }
    return 0;
}
