#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        if(len<2){
            return 0;
        }
/**
* 假如 k>len/2的情况,根据题意,必须先买后卖,那么对于n天交易,能够产生有效收益的交易次数是小于等于n/2的,
*只有不同天买卖才能产生差价。对于大于 n/2的那部分交易,必定是当天买卖没有任何收益的,无论交易多少次都是一样的
*所有 k>len/2,就相当于无限次交易
*/
        if(k > len /2){
            int ans=0;
            for(int i=1;i<len;++i){
                ans+=max(0,prices[i]-prices[i-1]);
            }
            return ans;
        }


        int* hold=new int[k+1];
        int*release=new int[k+1];
        memset(release,0,sizeof(int)*(k+1) );
        memset(hold,0x80,sizeof(int)*(k+1) );

        for(int i=0;i<prices.size();i++){
            for(int j=k;j>=1;j--){
                release[j]=max(release[j],hold[j] + prices[i]);
                hold[j] =max (hold[j],release[j-1] -prices[i]  );
            }
            /*
            release[0]=max(release[0],hold[0] + prices[i]);
            hold[0] =max (hold[0], -prices[i]  );
            */
        }
        return release[k];
    }
};


int main(){
    vector<int>vec;
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(9);
    vec.push_back(6);
    Solution  s;
    cout<<s.maxProfit(2,vec)<<endl;
    return 0;
}

