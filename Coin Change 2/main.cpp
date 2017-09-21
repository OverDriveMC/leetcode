#include<bits/stdc++.h>
using namespace std;
/**
dp[i][j]:使用前i种硬币凑成j元钱的方法数：

01背包:硬币不重复用
	dp[i][j]+=dp[i-1][j-coins[i]]
完全背包:无限硬币
	dp[i][j]+=dp[i][j-coins[i]]
使用滚动数组优化空间后,01背包内层循环逆序,完全背包内层循环顺序
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int *dp=new int[amount+1];
		memset(dp,0,sizeof(int)*(amount+1));
		dp[0]=1;
		for(int i=0;i<coins.size();i++){
			for(int j=coins[i];j<=amount;j++){
                if(dp[j-coins[i] ]!=-1){
                    dp[j]+=dp[j-coins[i]];
                }
			}
		}

		int result=dp[amount];
		delete[]dp;
		return result;
    }
};

int main(){
	vector<int>coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	Solution s;
	cout<<s.change(5,coins)<<endl;
	coins.clear();
	coins.push_back(2);
	cout<<s.change(3,coins)<<endl;
	coins.clear();
    coins.push_back(10);
	cout<<s.change(10,coins)<<endl;
	return 0;
}
