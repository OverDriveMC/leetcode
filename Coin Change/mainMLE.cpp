#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
		int **dp=new int*[amount+5];
		for(int i=0;i<amount+1;i++){
			dp[i]=new int[coins.size()+5];
		}
		for(int i=0;i<=amount;i++){
            for(int j=0;j<=coins.size();j++){
                dp[i][j]=0;
            }
		}
		sort(coins.begin(),coins.end());
        int result=dfs(coins,amount,coins.size()-1,dp);
        return result;
    }
    int dfs(vector<int>&coins,int amount,int index,int ** dp){
        //cout<<amount<<"  "<<index<<"  "<<dp[amount][index]<<endl;
        //假如为0,结果为0
        if(amount ==0){
            return 0;
        }else if(amount<0){
            return dp[amount][index]=-1;
        }
		if(dp[amount][index]!=0){
			return dp[amount][index];
		}

        if(index==0){
            if(amount % coins[index]==0){
                return amount /coins[index];
            }else{
                return -1;
            }
        }
        int result1=dfs(coins,amount,index-1,dp);
        int result2=-1;
        if(amount>=coins[index]){
            result2=dfs(coins,amount-coins[index],index,dp);
            ///可能无解,不能直接 +1
            if(result2!=-1){
                result2++;
            }
        }
        int result=-1;
        if(result1==-1){
            result=result2 ;
        }else{
            result=result2== -1 ? result1 : min(result1,result2);
        }
        return dp[amount][index]=result;
    }
};


int main(){
    Solution s;
    vector<int>coins;
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

    coins.clear();
    coins.push_back(288);
    coins.push_back(160);
    coins.push_back(10);
    coins.push_back(249);
    coins.push_back(40);
    coins.push_back(77);
    coins.push_back(314);
    coins.push_back(429);
    cout<<s.coinChange(coins,9208)<<endl;

    coins.clear();
    coins.push_back(370);
    coins.push_back(417);
    coins.push_back(408);
    coins.push_back(156);
    coins.push_back(143);
    coins.push_back(434);
    coins.push_back(168);
    coins.push_back(83);
    coins.push_back(177);
    coins.push_back(280);
    coins.push_back(117);
    cout<<s.coinChange(coins,9953)<<endl;


}



