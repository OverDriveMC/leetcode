#include<bits/stdc++.h>
using namespace std;

/**
Prices      3    1    2    8    3    1     9     6
release2    0    0    1    7    7    7    15    15
hold2      -3   -1   -1   -1    4    6     6     6
release1    0    0    1    7    7    7     8     8
hold1      -3   -1   -1   -1   -1   -1    -1    -1
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int release2=0,release1=0;
        int hold1=numeric_limits<int>::min(),hold2=hold1;
        for(int i=0;i<prices.size();i++){
            /**
            *release2: 在该价格点卖出第二笔股票后手里剩的钱,
            *  等于上一轮买入第二笔股票后手里剩的钱 + 卖出当前股票价格的钱
            *  or  上一轮卖出第二笔股票后手里剩的钱
            */
            release2=max(release2, hold2 +  prices[i]) ;
            /**
            * hold2:是在该价格点买入第二笔股票后手里剩的钱
            *    等于 上一轮卖出第一笔股票后手里剩的钱 - 买入当前股票价格的钱
            *    or  上一轮买入第二笔股票后手里剩的钱
            */
            hold2=max( hold2,  release1 - prices[i]);
            /**
            * release1:在该价格点卖出第一笔股票后手里剩的钱
            *  等于 上一轮买入第一笔股票后手里剩的钱加上卖出当前股票价格的钱
            *   or   上一轮卖出第一笔股票后手里剩的钱
            */
            release1=max(release1, hold1+ prices[i] );
            /**
            * hold1:在该价格点买入第一笔股票后手里剩的钱
            *   等于初始资金减去买入当前股票价格的钱
            *   或者初始资金
            */
            hold1=max(hold1, -prices[i]);

            cout<<release2<<" "<<hold2<<"  "<<release1<<" "<<hold1<<endl;
        }
        return release2;
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
    cout<<s.maxProfit(vec)<<endl;
    return 0;
}
