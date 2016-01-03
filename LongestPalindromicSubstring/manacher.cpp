#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=0){
            return s;
        }

        /// $#a#\0   $#a#a#\0
        int newLen=(s.length()<<1)+3;
        char newString[newLen];
        newString[0]='$';
        int cnt=1;
        for(int i=0;i<s.length();i++){
            newString[cnt++]='#';
            newString[cnt++]=s[i];
        }
        newString[newLen-2]='#';
        newString[newLen-1]='\0';

       // cout<<newString<<endl;
        int p[newLen];
        memset(p,0,sizeof(p));
        int id=0,maxId=0;
        int mIndex=1,maxL=1;
        for(int i=1;i<newLen;i++){
            if(maxId>i){
                p[i]=min(p[2*id-i],maxId-i);
            }else{
                p[i]=1;
            }
            while(newString[i+p[i]]==newString[ i-p[i] ]  ){
                p[i]++;
            }
            if( (i+p[i]) >maxId ){
                maxId=i+p[i];
                id=i;
            }
            ///当前回文串长度为p[i]-1
            if((p[i]-1)  >maxL){
                mIndex=i;
                maxL=p[i]-1;
            }

        }
        ///  $#a#\0    $#a#a#\0
       // cout<<"id:"<<mIndex<<"  "<<maxL<<endl;
        return s.substr((mIndex-maxL)/2,maxL);
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("babbabb")<<endl;
    cout<<s.longestPalindrome("abba")<<endl;
    cout<<s.longestPalindrome("aab")<<endl;
    cout<<s.longestPalindrome("a")<<endl;
    cout<<s.longestPalindrome("ab")<<endl;
    cout<<s.longestPalindrome("aabbaa")<<endl;
}
