#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string>res;
        sort(str.begin(),str.end());
        permutation(res,0,str);
        return res;
    }

    void permutation(vector<string>&res,int pos, string str ){

        if(pos==str.size()-1){
            cout<<pos<<"   "<<str<<endl;
            res.push_back(str);
            return ;
        }

        for(int i=pos;i<str.size();i++){
            if(i!=pos && str[i]==str[pos]){
                continue;
            }
            swap(str[i],str[pos]);
            permutation(res,pos+1,str);
        }
    }
};

int main(){
    Solution s;
    s.Permutation("abbc");
    return 0;
}
