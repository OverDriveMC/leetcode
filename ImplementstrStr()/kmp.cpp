#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }

        int *next=new int[needle.size()];
        getNext(needle,next);
//        cout<<needle<<endl;
//        for(int i=0;i<needle.size();i++){
//            cout<<next[i]<<"  ";
//        }
//        cout<<endl;


        int pos=0,k=0;
        while(pos<haystack.size()){
            while(k>0 && needle[k]!=haystack[pos]){
                k=next[k-1];
            }

            if(needle[k]==haystack[pos]){
                k++;
            }
            //cout<<"pos:"<<pos<<"  k:"<<k<<endl;
            if(k==needle.size()){
                return pos-k+1;
            }
            ///这里不需要更新k值，更新的话是当前段匹配结束
            ///找下一段匹配的时候，
//            k=next[k];
            pos++;
        }
        return -1;
    }
    ///aab
    void getNext(string &needle, int*next){
        next[0]=0;
        int k=0,pos=1;
        while(pos<needle.size()){
            ///注意，这里找到next是next[k-1]
            while(k>0 && needle[k]!=needle[pos]){
                k=next[k-1];
            }
            if(needle[k]==needle[pos]){
                k++;
            }
            ///更新当前的pos位的next数组
            next[pos]=k;
            pos++;
        }
    }
};

int main(){
    Solution s;
    cout<<s.strStr("abcd","aa")<<endl;
    cout<<s.strStr("abaacd","aa")<<endl;
    cout<<s.strStr("abaacaaad","aaa")<<endl;
    cout<<s.strStr("ababbaabcd","aab")<<endl;
    cout<<s.strStr("abcccadaaba","aba")<<endl;
    return 0;
}
