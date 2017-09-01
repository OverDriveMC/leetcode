

class Solution {
public:
    /**
    *  1 7  4 11
    *  0 6 -3 7
    *maxCur+=prices[i]-prices[i-1]
    * 11-4+(4-7)+(7-1)=11-1=10
    *即找最大连续子数组的和
    */
    int maxProfit(vector<int>& prices) {
        int maxCur=0,maxdiff=0;
        for(int i=1;i<prices.size();i++){
            maxCur=max(0,maxCur+prices[i]-prices[i-1]);
            maxdiff=max(maxdiff,maxCur);
        }
        return maxdiff;
    }
};
