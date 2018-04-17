#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string>res;
        if(str.size()==0){
            return res;
        }
        sort(str.begin(),str.end());
        permutation(res,0,str);
        return res;
    }
	/**
	传引用这种方法不行
	例如:abc
	第一个字符串是每次和自己做swap,得到abc
	第二个字符串是a和b swap =====> bac  
	第三个是ac swap    =========> bca    
	然后开始返回得到bac  abc
	开始开始ac互换 得到cba
	这样便不是字典序了
	*/
    void permutation(vector<string>&res,int pos, string& str ){
        cout<<pos<<"   "<<str<<endl;
        if(pos==str.size()){
            res.push_back(str);
            return ;
        }

        for(int i=pos;i<str.size();i++){
            if(i!=pos && str[i]==str[pos]){
                continue;
            }
            swap(str[i],str[pos]);
            permutation(res,pos+1,str);
            swap(str[i],str[pos]);
        }
    }
};

int main(){
    Solution s;
    s.Permutation("abc");
    return 0;
}
