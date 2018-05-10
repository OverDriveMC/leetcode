#include<bits/stdc++.h>
using namespace std;

vector<int> getNext(string str){
    int len=str.size();
    vector<int>next(len,0);
    int index=1,pos=0;
    while(index<len){
        while(pos>0 && str[pos]!=str[index] ){
            pos=next[pos-1];
        }
        if(str[pos]==str[index]){
            pos++;
        }
        next[index]=pos;
        index++;
    }
    return next;
}
class Solution {
public:
    string shortestPalindrome(string s) {
        string revs(s);
        reverse(revs.begin(),revs.end());
        string news=s+"#"+revs;
        vector<int>next=getNext(news);

        return revs.substr(0,revs.size()-next[news.size()-1]) + s;
    }
};
int main(){
    vector<int>next=getNext("cacacabc");
    for(int i=0;i<next.size();i++){
        cout<<next[i]<<"  ";
    }
    cout<<endl;
    Solution s;
    cout<<s.shortestPalindrome("aacecaaa")<<endl;
    return 0;
}
