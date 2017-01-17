#include<bits/stdc++.h>

using namespace std;
/**
*dp[i]代表从开头到下标i的合法的括号匹配数量
*(***) 假设s[i]是 ')',那么往前计算 start=i-dp[i-1]-1 (去掉dp[i-1]的合法括号匹配),假如是'(',那么说明[start,i]
*是一段合法序列,dp[i]=dp[i-1]+2
*同时,假如 start-1没有越界,那么两段合法括号匹配可以合并(必须当前段要是合法的,之前段也是合法的才能合并)
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<=1){
            return 0;
        }
        int *dp=new int[s.size()];
        int maxn=0;
        memset(dp,0,sizeof(int)*s.size());
        for(size_t i=1;i<s.size();i++){
            if(s[i]==')'){
                int start=i-1-dp[i-1];
                if(start>=0 && s[start]=='('){
                    dp[i]=dp[i-1]+2;
                    ///if要在括号内部,要保证当前段合法才能合并
                    if((start-1)>=0){
                        dp[i]+=dp[start-1];
                    }
                }
            }
            maxn=max(dp[i],maxn);
        }

        delete[]dp;
        return maxn;
    }
};

int main(){
    Solution s;
    cout<<s.longestValidParentheses("()()))))()()(")<<endl;
    cout<<s.longestValidParentheses("())")<<endl;
    cout<<s.longestValidParentheses(")()())")<<endl;
    cout<<s.longestValidParentheses("()()")<<endl;
    cout<<s.longestValidParentheses("(((())))")<<endl;
    cout<<s.longestValidParentheses("))")<<endl;
    cout<<s.longestValidParentheses("(()())")<<endl;
    return 0;
}
