#include<bits/stdc++.h>

using namespace std;
/**
*分两种情况
*一种是s[i]=')',s[i-1]='(', 字符串类似于 "...()"
*               dp[i]=dp[i-2]+2
*另一种是s[i]=')',s[i-1]=')',字符串类似于".....))"
*假如s[i-dp[i-1]-1]='(',那么
*                           dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2(加上之前的,可以合并)
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<=1){
            return 0;
        }
        int maxn=0;
        int *dp=new int[s.size()];
        memset(dp,0,sizeof(int)*s.size());
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=(i-2>=0? dp[i-2]:0)+2;
                }else{
                    if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                        dp[i]=dp[i-1]+2;
                        if(i-dp[i-1]-2>=0){
                            dp[i]+=dp[i-dp[i-1]-2];
                        }
                    }
                }
            }
            maxn=max(maxn,dp[i]);
        }

        delete []dp;
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
