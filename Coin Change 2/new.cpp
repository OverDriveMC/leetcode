/**

判断有多少种组成方式
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        if(coins.size()==0){
            return 0;
        }
		//这里不能开数组,开数组是放在栈空间,存不下
        vector<vector<int> >dp(coins.size(), vector<int>(amount+1,0));
        for(int i=0;i*coins[0]<=amount;i++ ){
			//只使用第一种硬币的情况,每种都是1种方式
            dp[0][i*coins[0] ]=1;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(j<coins[i]){
                    dp[i][j]=dp[i-1][j];
                }else{
					/**
					分成不使用第i种硬币,和使用第i种硬币
					*/
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i] ];
                }
            }
        }
        return dp[coins.size()-1][amount];
    }
};


/**
滚动数组优化
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        if(coins.size()==0){
            return 0;
        }
        vector<int >dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j] += dp[j-coins[i] ];
            }
        }
        return dp[amount];
    }
};