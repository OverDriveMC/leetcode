#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int vis[256];
        memset(vis,-1,sizeof(vis));
        int Max=0;
        int start=0;
        /**
        *保证当前 开始位+最大长度  < s.length()
        *这样可以保证 后面的无论重不重复都不可能超越当前最大长度
        *并且可以终止循环
        */
        while((start+Max)<s.length()){
            int cnt=0;
            for(int i=start;i<s.length();i++){
                ///因为start肯定>-1   保证重复的字母在开始位之前
                ///同时vis为最近一次出现
                if(vis[s[i]-'\0']==i || vis[s[i]-'\0']<start){
                    vis[s[i]-'\0']=i;
                    cnt++;
                }else{
                   start=vis[s[i]-'\0']+1;
                   ///更新位置为当前最近的位置
                   vis[s[i]-'\0']=i;
                   break;
                }
            }
            Max=max(cnt,Max);
        }
        return Max;
    }
};
int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("tmmzuxt")<<endl;
    cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<s.lengthOfLongestSubstring("bbbbbb")<<endl;
    cout<<s.lengthOfLongestSubstring("aab")<<endl;
    return 0;
}
