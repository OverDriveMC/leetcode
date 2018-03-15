/**
* 
判断单词能否由字典里字母组成
dp[i]:到第i个位置是否可以由字典中元素组成

dp[i] =true  if  dp[j]=true  &&  s.substring(j,i)可以在字典中找到 

*/

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean dp[]=new boolean[s.length()+1];
        dp[0]=true;
        
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<i;j++){
                if(dp[j]  &&  wordDict.contains(s.substring(j,i))){
                    dp[i]=true;
                }
            }
        }
        return dp[s.length()];
    }
}