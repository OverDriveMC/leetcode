#include<bits/stdc++.h>
using namespace std;
/**
*中心扩展法
*中心扩展就是把给定的字符串的每一个字母当做中心，
*向两边扩展，这样来找最长的子回文串
*/
class Solution {
public:
    string centralExtension(string s,int left,int right){
        while(left>=0 && right<s.length() &&s[left]==s[right]){
            left--;
            right++;
        }
        ///因为最后一个失配，所以是从left+1~right-1
        return s.substr(left+1,right-left-1);
    }
    /**
    *中心扩展法
    *01234
    *adcbb
    * 会有一个 3 3     3 4
    */
    string longestPalindrome(string s) {
        string maxString=string(1,s[0]);
        for(int i=0;i<s.length();i++){
            ///  xxx i xxx这种类型的回文串
            string temp=centralExtension(s,i,i);
            if(temp.length()>maxString.length()){
                maxString=temp;
            }
            /// xxx i i xxx中间没有单独的这种类型的回文串
            temp=centralExtension(s,i,i+1);
            if(temp.length()>maxString.length()){
                maxString=temp;
            }
        }
        return maxString;
    }
};
int main(){
    Solution s;
    cout<<s.longestPalindrome("a")<<endl;
    cout<<s.longestPalindrome("abb")<<endl;
    cout<<s.longestPalindrome("aaaaaa")<<endl;
    cout<<s.longestPalindrome("aabbaa")<<endl;
    cout<<s.longestPalindrome("abcd")<<endl;
}
