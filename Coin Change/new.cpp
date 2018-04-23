/**
每个硬币数量不限
求组成amount使用最少的硬币的方式,假如没有返回-1

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
/**
最朴素的方式,先排序,然后暴力搜索
*/

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        int res=0x3f3f3f3f;
        search(coins, amount,0,0, res);
        return res==0x3f3f3f3f ? -1 : res;
    }
    void search(vector<int>&coins, int amount, int index,int cures, int& res ){
/**
假如amount==0,说明已经搜出了结果,小于0说明得不到结果
*/
        if( amount==0){
            res=min(res, cures);
            return ;
        }else if(amount<0){
            return ;
        }
/**
下标越界之后,也说明得不到结果
*/
        if(index>= coins.size()){
            return ;
        }
/**
假如amount是coins[index]的倍数,那么直接便可以得到结果
*/
        if(amount % coins[index] ==0){
            res=min(res, cures + amount/coins[index]);
            return ;
        }
/**
每次分为当前的硬币选与不选
*/
		search(coins, amount-coins[index], index, cures+1, res);
        search(coins, amount, index+1, cures, res);
    }
};


/**
dp[i][j] =min(dp[i-1][j-k*coins[i]]+k )
	第i个硬币选k个
注意第0维要手动枚举
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        int dp[coins.size() ][amount+1];
        memset(dp,0x3f3f3f3f, sizeof(dp));

        for(int i=0;i*coins[0]<=amount;i++ ){
            dp[0][i*coins[0] ]=i;
        }
        for(int i=1;i<coins.size();i++){
			//注意,这里一定要从0开始,不能从coins[i]开始,否则dp[i][0]没法往回传
			//例如amount==0的时候,循环根本不会进入  dp[i][0]一直都是0x3f3f3f3f(i>0)
			//主要是例如 5 3 1 amount=1
			//因为dp[0][0]=0   dp[1][0]不会等于0 (因为amount==1<3不会进入循环) 导致dp[2][1]是根据dp[1][0]更新的也不会成功
			//而如果是3 1的话 amount=1
			//那么dp[1][0]根据dp[0][0]更新就可以成功
			
			//所以注意这里一定要从0开始
            for(int j=0;j<=amount;j++){
                for(int k=0; k*coins[i]<=j;k++ ){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-k*coins[i]]+k );
                }
            }
        }
        /*
        for(int i=0;i<coins.size();i++ ){
            for(int j=0;j<=amount;j++){
                cout<<i<<"   "<<j<<"  "<<dp[i][j]<<endl;
            }
        }
        */
        return dp[coins.size()-1][amount]==0x3f3f3f3f ? -1 :dp[coins.size()-1][amount];
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        int dp[coins.size() ][amount+1];
        memset(dp,0x3f3f3f3f, sizeof(dp));

        for(int i=0;i*coins[0]<=amount;i++ ){
            dp[0][i*coins[0] ]=i;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
				/**
				可以不用枚举k,
				直接判断假如j<coins[i] 那么说明当前选不了
				否则的话 每次比较dp[i-1][j] 不选  和 选的大小
				0-1
				*/
                if(j<coins[i]){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
                }
            }
        }
        return dp[coins.size()-1][amount]==0x3f3f3f3f ? -1 :dp[coins.size()-1][amount];
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        int dp[amount+1];
        memset(dp,0x3f3f3f3f, sizeof(dp));
		/**
		滚动数组优化
		注意,这里下标从0开始
		j按照正序,因为coins[i]取2个的时候 依据取1个的值,取3个的之后,依据取2个的值
		*/
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
        return dp[amount]==0x3f3f3f3f ? -1 :dp[amount];
    }
};

int main(){
    Solution s;
    vector<int>coins;
    coins.push_back(265);
    coins.push_back(398);
    coins.push_back(46);
    coins.push_back(78);
    coins.push_back(52);
    cout<<s.coinChange(coins,7754)<<endl;
    coins.clear();
    coins.push_back(1);
    coins.push_back(2147483647);
    cout<<s.coinChange(coins,2)<<endl;
    coins.clear();
    coins.push_back(1);
    coins.push_back(2);
    cout<<s.coinChange(coins,3)<<endl;
    coins.clear();
    coins.push_back(1);
    coins.push_back(2);
    cout<<s.coinChange(coins,2)<<endl;

    coins.clear();
    coins.push_back(186);
    coins.push_back(419);
    coins.push_back(83);
    coins.push_back(408);
    cout<<s.coinChange(coins,6249)<<endl;
    return 0;
}
