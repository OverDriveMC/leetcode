/**
Repeated Substring Pattern
给一个非空的字符串,判断它能否由子串copy得到
Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

最短循环节:  len- next[len-1]
判断是否  len % (len-next[len-1]) 同时 最短循环节不能等于原串
*/

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int>next(s.size(),0);
        int pos=0,index=1;
        while(index<s.size()){
            while(pos>0 && s[pos]!=s[index] ){
                pos=next[pos-1];
            }
            if(s[pos]==s[index]){
                pos++;
            }
            next[index]=pos;
            index++;
        }
        int leastLen= s.size()- next[ s.size()-1 ];
        return   leastLen!=s.size() && s.size() % leastLen==0;
    }
};
int main(){
    Solution s;
    cout<<s.repeatedSubstringPattern("aaab")<<endl;
}
