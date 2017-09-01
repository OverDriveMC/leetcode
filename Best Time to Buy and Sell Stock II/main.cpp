#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        for(int i=1;i<prices.size();i++){
            /**
            * 只要维护下相邻的差即可,
            * 1 2 3 4  3 5
            * 0 1 1 1 -1 2
            * 1--4 =4=1+1+1
            * 5-3=2
            * 只要在最低买,出现降之前卖即可
            */
            sum+=max(0,prices[i]-prices[i-1]);
        }
        return sum;
    }
};


