/*
类似斐波那契数列
定义dp[i]:到第i个位置(对应字符串i-1的位置)有多少种解析方式
dp[0]=1,因为会特别判断是否加dp[i-2],dp[i-1]所以要置为1

分两种情况:
	第i-1个字符串为1-9之间的数字,那么可以解析为dp[i-1]种方式.
	第i-2个字符和第i-1个字符是10-26之间的数字,那么剩下的有dp[i-2]种解析方式
所以最后返回dp[s.length()]
*/


class Solution {
    public int numDecodings(String s) {
        if(s==null || s.length()==0){
            return 0;
        }
        int dp[]=new int[s.length()+1];
        dp[0]=1;
        dp[1]= s.charAt(0) =='0'? 0 : 1;
        for(int i=2;i<=s.length();i++){
            dp[i]=0;
            int second=s.charAt(i-1)-'0';
            int first=(s.charAt(i-2)-'0')*10+second;
            if(second>=1 && second <=9){
                dp[i]+=dp[i-1];
            }
            if(first>=10 && first<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.length()];
    }
	

}