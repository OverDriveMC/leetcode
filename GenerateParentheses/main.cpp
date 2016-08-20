#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        if(n<0){
            return res;
        }
        generator(0,0,n,"",res);
        return res;
    }
    /**
    * l 当前字符串s中的左括号数量
    * r 当前字符串s中的右括号数量
    * n 一共可以使用的左括号数量(即完整的括号数量)
    * s 当前正在递归的字符串
    * res 结果容器
    */
    void generator(int l,int r,int n,string s,vector<string> &res){
        /**
        *当左括号用完的情况下，将剩余的右括号数量全部加进去
        *完成匹配
        */
        if(l==n){
            res.push_back(s.append(n-r,')'));
            return ;
        }
        /**
        *假如左括号数量大于右括号数量，那么可以进行两种情况
        *一种是下面一个是右括号
        *另一种是下面一个是左括号
        */
        if(l>r){
            generator(l,r+1,n,s+')',res);
        }
        /**
        *无论左括号数量多不多于右括号数量
        *都有一种情况是下一个添加的为左括号
        */
        generator(l+1,r,n,s+'(',res);

    }
};

int main(){
    Solution s;
    vector<string> res=s.generateParenthesis(3);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
