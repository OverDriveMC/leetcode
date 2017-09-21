#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int result=dfs(coins,amount,coins.size()-1);
        return result;
    }
    int dfs(vector<int>&coins,int amount,int index){
        //假如为0,结果为0
        if(amount ==0){
            return 0;
        }else if(amount<0){
            return -1;
        }
        if(index==0){
            if(amount % coins[index]==0){
                return amount /coins[index];
            }else{
                return -1;
            }
        }
        int result1=dfs(coins,amount,index-1);
        int result2=-1;
        if(amount>=coins[index]){
            result2=dfs(coins,amount-coins[index],index);
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
        return result;
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
}



