#include<bits/stdc++.h>
using namespace std;
/**
用dp[i][j]表示字符串s的前i个字符和字符串p的前j个字符是否匹配
当p[j-1]不为 *的情况下

当s[i-1]==p[j-1] 或者p[j-1]=='?' 并且dp[i-1][j-1]为true时
dp[i][j]= true

当p[j-1]为*的时候
假设dp[i-1][j-1]==true  那么*可以匹配 s中i-1 ->s.length()中的所有字符
所以都为true
假如dp[i][j-1]==true  那么*可以匹配 i->s.length()中的所有字符


如果p的当前字符为'*'号，那么可以分两种情况：

(1) 如果dp[i-1][j-1]，那么p的前j个字符和s的前k(i-1<=k<=len_s)个字符都匹配，注意这里有一个i-1，因为*可以匹配空串。

(2)如果dp[i][j-1]，即s的前i个字符和字符串p的前j-1个字符，那么p的前j个字符和s的前k(i<=k<=len_s)个字符匹配，注意这里没有i-1，因为这是让*去匹配i后面的字符串。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        /**
        *防止s为空，p为***的组合
        */
        if(s.length()==0){
            for(int i=0;i<p.length();i++){
                if(p[i]!='*'){
                    return false;
                }
            }
            return true;
        }


		bool dp[s.size()+1][p.size()+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=true;

        for(int j=1;j<=p.length();j++){
            for(int i=1;i<=s.length();i++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
					//需要判断一下dp[i-1][j-1]是否为true
                    if(dp[i-1][j-1]){
                        dp[i][j]=true;
                    }
                }else if(p[j-1]=='*'){
                    if(dp[i-1][j-1]){
						/**
						*			"aa"
						*			"*"
						*/
                        for(int k=i-1;k<=s.length();k++){
                            dp[k][j]=true;
                        }
                        break;
                    }else if(dp[i][j-1]){
						/**
						*			"a"
						*           "a*"
						*/
                        for(int k=i;k<=s.length();k++){
                            dp[k][j]=true;
                        }
                        break;
                    }
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};

int main(){
    Solution s;
    cout<<s.isMatch("aa","a")<<endl;
    cout<<s.isMatch("aa","aa")<<endl;
    cout<<s.isMatch("aaa","aa")<<endl;
    cout<<s.isMatch("aa", "*")<<endl;
    cout<<s.isMatch("aa", "a*")<<endl;
    cout<<s.isMatch("ab", "?*")<<endl;
    cout<<s.isMatch("aab", "c*a*b")<<endl;
    return 0;
}








