#include<bits/stdc++.h>

/**
dp[i][j]:
    word1的第0个位置到第i个位置与
    word2的第0个位置到第j个位置匹配
    word1[0...i-1]   word2[0...j-1]
    both i and j 从1 开始
临界条件:
    从word1[0...i-1] to ""   需要 i 步(删除)
  所以临界条件为:
	dp[i][0]=i
	dp[0][j]=j
一般情况:
	从word1[0...i-1] to word2[0...j-1] 
首先考虑word1[0...i-2] to word2[0...j-2] == dp[i-1][j-1]
接下来考虑word1[i-1]与word2[j-1]:
	假如他们相等,那么不需要任何操作,dp[i][j]==dp[i-1][j-1]
	假如不相等,会有三种情况:
		1: 使用word2[j-1]替换word1[i-1]
			那么: dp[i][j] =dp[i-1][j-1]+1
		2: 删掉word1[i-1],然后使word1[0...i-2] ==word2[0...j-1]
			那么:dp[i][j]=dp[i-1][j] +1(for deletion)
			convert word1[0...i-2] to word2[0...j-1] 花费dp[i-1][j]
			之后删掉word1[i-1] 花费1
		3: 插入word2[j-1]于word1[0...i-1],然后使word1[0...i-1]+word2[j-1]=word2[0...j-1]
			dp[i][j]=dp[i][j-1]+1 (for insertion)
			将word1[0...i-1]转换为word2[0...j-2]  花费dp[i][j-1]
			插入word2[j-1]于word1[0...i-1] 花费1

dp[i][0]=i
dp[0][j]=j
dp[i][j]=dp[i-1][j-1] if word1[i-1]	==word2[j-1]
dp[i][j] =min(dp[i-1][j-1]+1 ,dp[i-1][j]+1, dp[i][j-1]+1) 		
*/
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        int ** dp=new int*[len1+1];

        for(int i=0;i<=len1;i++){
            dp[i]=new int[len2+1];
        }

        ///初始化
        for(int i=0;i<=len1;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=len2;j++){
            dp[0][j]=j;
        }

        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1[i-1] == word2[j-1] ){
                    dp[i][j] =dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j-1]+1,
                                   min(dp[i-1][j]+1 , dp[i][j-1]+1 )  );
                }
            }
        }
        int result=dp[len1][len2];
        delete []dp;
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.minDistance("","abcd")<<endl;
    cout<<s.minDistance("abcd","")<<endl;
    cout<<s.minDistance("intention","execution")<<endl;
    return 0;
}
