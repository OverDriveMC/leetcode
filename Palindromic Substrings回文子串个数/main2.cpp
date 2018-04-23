#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()==0){
            return 0;
        }
        int res=0;
        for(int i=0;i<s.size();i++){
			/**
			中心扩展法
			每次以i为中心(回文串长度为奇数),或者 (i,i+1)为中心(回文串长度为偶数)
			*/
            count(s,i,i,res);
            count(s,i,i+1,res);
        }
        return res;
    }
    void count(const string &s,int left,int right, int& res ){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            res++;
            left--;
            right++;
        }
        cout<<left<<"  "<<right<<endl;
    }
};

int main(){
    Solution s;
    cout<<s.countSubstrings("aaa")<<endl;
    return 0;
}
