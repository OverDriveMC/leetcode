#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty() ){
            return "";
        }
        string result=strs[0];
        for(int i=1;i<strs.size();i++){
            result=getCommonPrefix(result,strs[i]);
        }
        return result;
    }
    /**
    *每次将之前的最长前缀与之后的字符串进行比较
    *取最长前缀，直到最后即为公共最长前缀
    */
    string getCommonPrefix(string str1,string str2){
        int size=min(str1.size(),str2.size());
        int last=0;
        for(int i=0;i<size;i++){
            if(str1[i]!=str2[i]){
                break;
            }
            last++;
        }
        return str1.substr(0,last);
    }
};
int main(){
    Solution s;
    vector<string>strs;
    strs.push_back("aaa");
    strs.push_back("aa");
    strs.push_back("ab");
    strs.push_back("a");
    cout<<s.longestCommonPrefix(strs)<<endl;
    return 0;
}
