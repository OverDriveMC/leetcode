#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param s: a string
     * @return: return a string
     */
    string encode(string &s) {
        int n=s.size();
		vector<vector<string>> dp(n,vector<string>(n,""));
		for(int len=1;len<=n;len++){
			for(int i=0;i<=n-len;i++){
				int j=i+len-1;
				string subs=s.substr(i,len);
				dp[i][j]=subs;
				if(len<4){
					continue;
				}
				for(int k=i;k<j;k++){
					if(dp[i][k].size()+ dp[k+1][j].size() < dp[i][j].size() ){
						dp[i][j]=dp[i][k]+dp[k+1][j];
					}
				}
				int rlen=kmp(subs);
				if(rlen<len){
					string repeat= to_string(len/rlen) +'[' + dp[i][i+rlen-1] +']';
					if(repeat.size()<dp[i][j].size()){
						dp[i][j]=repeat;
					}
				}

			}
		}
		return dp[0][n-1];
    }
    ///利用KMP算法来寻找和判断是否存在重复的子串
	int kmp(string&s){
		int len=s.size();
		vector<int>next(len,0);
		int index=1,pos=0;
		while(index<len){
			while(pos>0 && s[pos]!= s[index]){
				pos=next[pos-1];
			}
			if(s[pos]==s[index]){
				pos++;
			}
			next[index]=pos;
			index++;
		}
		int leastCommonLen= len- next[len-1];
		if(len% leastCommonLen==0){
			return leastCommonLen;
		}else{
			return len;
		}
	}
};


int main(){
    Solution s;
    string str="abbbabbbcabbbabbbc";
    cout<<s.encode(str)<<endl;
    return 0;
}
