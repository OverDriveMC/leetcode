#include<bits/stdc++.h>

using namespace std;

/*
01背包:
F[i,v]:表示前i件物品恰放入一个容量为v的背包可以获得的最大价值
F[i,v]=max{F[i-1,v],F[i-1,v-Ci]+Wi}
若只考虑第i件物品的策略(放或者不放),那么就可以转化为一个只和前i-1件物品相关的问题。
    如果不放第i件物品,那么问题就转换成"前i-1件物品放入容量为v的背包中",价值为F[i-1,v]
    如果放第i件物品,那么问题就转化为"前i-1件物品放入剩下的容量为v-Ci的背包中",此时能获得
	    的最大价值就是F[i-1,v-Ci]再加上通过放入第i件物品获得的价值Wi

如果只用一个数组F[0...V],怎么样保证第i次循环结束后F[v]中表示的就是定义的状态F[i,v]呢？
F[i,v]由F[i-1,v]和F[i-1,v-Ci]两个子问题递推而来,
每次主循环中以 v<-V...0的递减顺序计算F[v],这样才能保证计算F[v]时F[v-Ci]保存的是F[i-1,v-Ci]的值
如果正序的话,例如计算F[2], F[2]=max(F[2],F[0]+1)
那么算F[4]=max(F[4],F[2]+1),这时的F[2]已经更新了,已经是F[i,v]的值而不是F[i-1,v]的值

*/


/**
完全背包:
F[i,v]:表示前i种物品恰好放入一个容量为v的背包的最大权值
F[i,v]=max{F[i-1,v-k * Ci] +kWi  | 0<=kCi <=v  } 
01背包按照v递减的次序来循环,让v递减是为了保证第i次循环中的状态F[i,v]是由状态F[i-1,v-Ci]递推而来
换句话说,这正是为了保证每件物品可选无限件,所以在考虑"加选一件第i种物品"这种策略时,却正需要一个可能已选入
第i种物品的子结果F[i,v-Ci],所以就可以并且必须采用v递增的顺序循环。
01背包逆序：是为了max中的两项是前一状态值,
这里顺序写,这里的max中的两项是当前状态的值,因为每种背包都是无限的,当把i从1到N循环时,
f[v]表示容量v在前i种背包时所得的价值,这里要添加的不是前一个背包,而是当前背包,所以要考虑
的是当前状态。

*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *dp=new int[amount+1];
        memset(dp,0x3f3f3f3f,sizeof(int)*(amount+1));
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]=min(dp[j-coins[i]]+1,dp[j]);
            }
        }
		/**
		大于amount,说明一直没有得到更新,达到不了 减到0的位置
		*/
        int result=dp[amount] > amount ? -1 : dp[amount];
        delete[]dp;
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



