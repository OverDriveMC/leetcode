#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        bool flag=true;
        int lastpos=haystack.size()-needle.size();
        for(int i=0;i<=lastpos;i++){
            int start=i;
            flag=true;
            for(int j=0;j<needle.size();j++){
                if(haystack[start++]!=needle[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }
};


int main(){
    Solution s;
    cout<<s.strStr("aaaa","a")<<endl;
    cout<<s.strStr("aaaa","ab")<<endl;
    cout<<s.strStr("aaba","ab")<<endl;
    cout<<s.strStr("abaaa","aaa")<<endl;
    return 0;
}
