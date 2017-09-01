#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1){
            return 0;
        }
        int maxdiff=0;
        int maxn=prices[0],minn=prices[0];
        for(int i=1;i<prices.size();i++){
            /**
            * 分别讨论prices[i]的范围
            * 假如比 minn还要小,那么更新maxn与minn的范围(因为maxn必须要在minn之后出现)
            * minn肯定可以更新(后面同一个maxn,minn更新必定保持maxdiff减小)
            * 假如在 minn 与 maxn之间,没有更新的意义
            * 假如大于maxn,更新maxn,同时判断maxdiff是否要更新
            */
            if(prices[i]<minn){
                minn=prices[i];
                maxn=prices[i];
            }else if(prices[i]>maxn){
                maxn=prices[i];
                maxdiff=max(maxdiff,maxn-minn);
            }
        }
        return maxdiff;
    }
};


int main(){
    vector<int>vec;
    vec.push_back(7);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(4);
    Solution s;
    cout<<s.maxProfit(vec)<<endl;
    vec.clear();
    vec.push_back(7);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(1);
    cout<<s.maxProfit(vec)<<endl;
    return 0;
}
