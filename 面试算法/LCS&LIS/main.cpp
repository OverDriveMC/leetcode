#include <bits/stdc++.h>

using namespace std;
const int maxn=100;
char str1[maxn],str2[maxn];
int dp[maxn][maxn];
int main()
{
    freopen("1.txt","r",stdin);
    memset(dp,0,sizeof(dp));
    scanf("%s%s",str1,str2);
    int len1=strlen(str1);
    int len2=strlen(str2);
    for(int i=0;i<len2;i++){
        if(str1[0]==str2[i]){
            dp[0][i]=1;
        }
    }
    for(int i=0;i<len1;i++){
        if(str1[i]==str2[0]){
            dp[i][0]=1;
        }
    }
    int maxLen=0;
    int x=len1;
    for(int i=1;i<len1;i++){
        for(int j=1;j<len2;j++){
            if(str1[i]==str2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(maxLen<dp[i][j]){
                    maxLen=max(maxLen,dp[i][j]);
                    x=i;
                }
            }
        }
    }
	//最长公共子串,记录下最长长度,以及截至的长度,便可以推出来位置
	//dp[i][j]表示str1以i为截止位置,str2以j为截止位置的最长公共子串长度(都是一定包含)
    cout<<"common:"<<endl;
    for(int i=x-maxLen+1;i<=x;i++){
        cout<<str1[i];
    }
    cout<<endl;
    cout<<maxLen<<endl;

    int vis[len1][len2];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(str1[i]==str2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
				//被选中,设置为1
                vis[i][j]=1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
	
    maxLen=dp[len1-1][len2-1];
    vector<char>vec;
    for(int i=len1-1;i>=0;i--){
        for(int j=len2-1;j>=0;j--){
			/**
			每次会推被选中的字符,并且dp[i][j]=maxLen
			maxLen每次减1
			*/
            if(vis[i][j]==1 && dp[i][j]==maxLen   ){
                vec.push_back(str1[i]);
                maxLen--;
            }
        }
    }
    for(int i=vec.size()-1;i>=0;i--){
        cout<<vec[i];
    }
    cout<<endl;
    cout<<dp[len1-1][len2-1]<<endl;


    vec.clear();
    int pos[maxn];
    for(int i=0;i<len1;i++){
        if(vec.empty()){
            vec.push_back(str1[i]);
            pos[i]=1;
        }else if(vec[0]>str1[i]){
            vec[0]=str1[i];
            pos[i]=1;
        }else if(vec[vec.size()-1 ] <str1[i]){
            vec.push_back(str1[i]);
            pos[i]=vec.size();
        }else{
            int index=upper_bound(vec.begin(),vec.end(),str1[i])-vec.begin();
            vec[index]=str1[i];
            pos[i]=index+1;
        }
    }
    cout<<"最长上升子序列:";
    vector<char>res;
    maxLen=vec.size();
    int num=0x7fffffff;
    for(int i=len1-1;i>=0;i--){
		/**
		从后往前找,只要找到比下一个位置值小,并且子序列长度为maxLen的
		maxLen每次减1
		*/
        if(pos[i]==maxLen && str1[i]<num){
            res.push_back(str1[i]);
            num=str1[i];
            maxLen--;
        }
    }
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    cout<<vec.size()<<endl;
    return 0;
}
