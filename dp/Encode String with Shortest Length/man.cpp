/**
给一个非空字符串,将它编码为最短长度
编码规则为： k[encoded_string]
Input: "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
Example 2:

Input: "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
Example 3:

Input: "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".
Example 4:

Input: "aabcaabcd"
Output: "2[aabc]d"
Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".
Example 5:

Input: "abbbabbbcabbbabbbc"
Output: "2[2[abbb]c]"
Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".

*/
/**
https://www.lintcode.com/problem/encode-string-with-shortest-length/description
这个字符串编码的可能性有很多种,所以DP的方式就是对于每一种可能都求出一个结果最后得到最短的那个
dp[i][j]:代表编码后的子串从i开始到j结束
枚举每一个子串都具有编码和不编码的可能性,

dp[i][j] = argminLength(s.substring(i,j) , dp[i][k]+dp[k+1][j]  ) after repeat s.substring()
总的来说就是枚举两种情况:
一种是  i-j 完全压缩的情况   例如    abc abc  abc  abc  ====>  4[abc]
一种是  i-k 压缩, k+1-j这部分一起压缩   ===> abcabcabc  abababab ====> 2[abc]4[ab]
两种情况取小的即可

完全压缩的时候,假如字符串为 t="abab"
采用 t+t ="abababab"
然后在新串里查找第二个t出现的位置,从1位置开始查找,小于t的长度4
如果t中有重复出现,重复的个数为t.size()/pos=2个
那么把重复的地方放入中括号中,注意中括号里不能直接放这个子字符串,而是应该从dp中取出对应位置的压缩字符串,因为
重复的部分可能已经写成缩写形式。
时间复杂度O(n^3) 空间复杂度O(n^2)
*/


#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    string encode(string s) {
        int n=s.size();
        //每维是一个长度为n的""组合
        vector<vector<string>> dp(n,vector<string>(n,"") );
        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                dp[i][j]=s.substr(i,len);
                if(len<4){
                    continue;
                }
                for(int k=i;k<j;k++){
                    if( dp[i][k].size() +dp[k+1][j].size() <dp[i][j].size() ){
                        dp[i][j]=dp[i][k]+dp[k+1][j];
                    }
                }
				//下面枚举完全压缩的情况
                string t=s.substr(i,len),replace="";
				/**
				string.find(pattern, position)
				从string串的position位置开始查找pattern串,返回出现的位置下标
				如果没有出现返回npos==4294967295 表示
				*/
                auto pos=(t+t).find(t,1);
                if(pos>=t.size()){
                    replace=t;
                }else{
					///注意这里使用 dp[i][i+pos-1]压缩后的情况,而不是使用原串
                    replace=to_string(t.size()/pos) + '[' + dp[i][i+pos-1] +']';
                }
                if(replace.size()<dp[i][j].size()){
                    dp[i][j]=replace;
                }

            }
        }
        return dp[0][n-1];
    }
};

int main(){
    Solution s;
    cout<<s.encode("abbbabbbcabbbabbbc")<<endl;
    cout<<s.encode("abcabcabcabcabc")<<endl;
}
