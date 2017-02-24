#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<char>vec;
        vec.push_back('1');
        for(int i=1;i<n;i++){
            vector<char>vec2;
            for(int j=0;j<vec.size();){
                int cnt=1;
                int k=j+1;
                while(k<vec.size() && vec[j]==vec[k]  ){
                    cnt++;
                    k++;
                }
                vec2.push_back(cnt+'0');
                vec2.push_back(vec[j]);
                j=k;
            }
            vec.resize(vec2.size());
            copy(vec2.begin(),vec2.end(),vec.begin());
        }
        string str(vec.begin(),vec.end());
        return str;
    }
};

int main(){
    Solution s;
    for(int i=1;i<10;i++){
        cout<<i<<": "<<s.countAndSay(i)<<endl;
    }
    return 0;
}
