#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n){
            res.push_back('A' + (n-1)%26);
            n=(n-1)/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution2 {
public:
    string convertToTitle(int n) {
        return n==0 ? "" : convertToTitle(n/26 ) +(char)('A' + (--n)%26);
    }
};

int main(){
    Solution2 s;
    cout<<s.convertToTitle(1)<<endl;
    cout<<s.convertToTitle(26)<<endl;
    cout<<s.convertToTitle(27)<<endl;
    cout<<s.convertToTitle(53)<<endl;
    cout<<s.convertToTitle(703)<<endl;
    return 0;
}
