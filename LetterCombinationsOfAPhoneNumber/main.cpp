#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>vec;
        vector<string>res;
        ///需要特判一下，否则会返回  ""
        if(digits.size()==0){
            return res;
        }
        init(vec);
        dfs(digits,vec,0,0,res,"");
        return res;
    }
    ///tindex 代表遍历到digits的第几位
    ///sindex代表遍历到tindex位数字映射的字符串的第几位
    ///实际sindex不必要这个参数，因为实际这个在for循环里面依次遍历了
    ///所以实际每次传过来的都是下一位的第一个字母0
    void dfs(string digits, vector<string>&vec, int tindex,
             int sindex,vector<string> &res,string str){
        if(tindex==(digits.size())){
            res.push_back(str);
            return ;
        }
        for(int i=0;i<vec[digits[tindex]-'0'].size();i++){
            /**
            *将当前位选进去，然后开始遍历下一位的第0个字母开始
            */
            dfs(digits,vec,tindex+1,0,res,str+vec[digits[tindex]-'0'][i]);
        }
    }
    void init(vector<string>&vec){
        vec.resize(10);
        vec[2]="abc";
        vec[3]="def";
        vec[4]="ghi";
        vec[5]="jkl";
        vec[6]="mno";
        vec[7]="pqrs";
        vec[8]="tuv";
        vec[9]="wxyz";
    }
};
int main(){
    Solution s;
    vector<string> vec=s.letterCombinations("234");
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
