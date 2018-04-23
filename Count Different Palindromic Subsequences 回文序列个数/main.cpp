/**
题目描述：
计算字符串中回文序列的个数(同一个字符串算重复)
Input:
S = 'bccb'
Output: 6
Explanation:
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
*/

/**
定义dp[i][j]为从i到j的回文序列个数
当s[i]!=s[j]时,例如 abbc
		i=0 j=3    dp[0][3]=dp[0][2]+dp[1][3] -dp[1][2]
		dp[0][2] ={{a},{b},{bb} }
		dp[1][3] ={{b},{bb},{c}}
		dp[1][2] ={{b},{bb}}
		中间的dp[i+1][j-1]会被多算一次
当s[i]==s[j]时,分为三种情况
	1. 例如 a...a ,在他们之间没有字符等于a的情况,例如aba
		这时候i=0,j=2  dp[1][1]=1={b}
		dp[0][2] =2*dp[1][1] + 2
		2*dp[1][1]:因为记录一次[i+1][j-1] {b},同时[i+1][j-1]之间的回文串还可以与a组成新的 {aba}
		加2因为多了两个新的回文串 {{a},{aa}}
		所以总的回文串为{a,b,aa,aba}
		dp[i][j]= 2* dp[i+1][j-1] +2
	2. 当中间有一个字符与两边相同时,a...a...a,例如aaa
		这时候i=0,j=2, dp[1][1]=1={a}
		dp[0][2]=2*dp[1][1]+1
		同样,2*dp[1][1]:因为记录一次dp[1][1] {a},同时记录[i+1][j-1]之间的回文串与边界的a组成新的回文串{aaa}
		因为{a}在dp[1][1]中已经有记录,所以在加1,记录上{aa}
		所以总的回文串为{a,aa,aaa}
		dp[i][j]=2*dp[i+1][j-1]+1
	3. 当中间有至少两个字符与两边相同时, a...a...a...a,例如aacaa
	   此时i=0,j=4, dp[i+1][j-1]={{a},{c},{aa},{aca}}
	   dp[i+1][j-1]*2,因为既记录了dp[i+1][j-1]={{a},{c},{aa},{aca}}
	   又额外加了这些串与边界的字符串组成的新的回文串{{aaa},{aca},{aaaa},{aacaa}}
	   这时候会有重复的{aca}
	   所以需要记录第一个与左边s[i]相同的字符串下标low
	   第一个与右边s[j]相同的字符串下标high
	   dp[low+1][high-1]之间的部分都会被重复(因为他们都曾经与s[low],s[high]组成过与 s[i]、s[j]相同的回文串) {aca}
	   所以最后dp[i][j]={a,c,aa,aca,aaa,aaaa,aacaa}
		dp[i][j]=2*dp[i+1][j-1] -dp[low+1][high-1]
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	const int mod=1e9+7;
    int countPalindromicSubsequences(string S) {
		int slen=S.size();
		int dp[slen+5][slen+5];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<slen;i++){
			dp[i][i]=1;
		}
		for(int len=2;len<=slen;len++){
			for(int i=0;i<=slen-len;i++){
				int j=i+len-1;
				if(S[i]!=S[j]){
					dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
				}else{
					int low=i+1;
					int high=j-1;
					while(low<j && S[low]!=S[i]){
                        low++;
					}
					while(high>i && S[high]!=S[j]){
                        high--;
					}
					if(low>high){
						dp[i][j]=2*dp[i+1][j-1]+2;
					}else if(low==high){
						dp[i][j]=2*dp[i+1][j-1]+1;
					}else{
						dp[i][j]=2*dp[i+1][j-1]-dp[low+1][high-1];
					}
				}
				//最后统一,小于0的时候+mod,然后取模
				//感觉上是因为*2,会越界(主要还是要判断是否小于0)
				dp[i][j]=dp[i][j]<0 ? dp[i][j]+mod  : dp[i][j]%mod;
			}
		}
		return dp[0][slen-1]%mod;
    }
};

int main(){
    //freopen("1.txt","r",stdin);
    Solution s;
    cout<<s.countPalindromicSubsequences("bcbacbabdcbcbdcbddcaaccdcbbcdbcabbcdddadaadddbdbbbdacbabaabdddcaccccdccdbabcddbdcccabccbbcdbcdbdaada")<<endl;
    return 0;
}
