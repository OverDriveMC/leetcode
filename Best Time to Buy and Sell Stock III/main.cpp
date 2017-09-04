#include<bits/stdc++.h>

using namespace std;
/**
*分别得出以i点为分割点，左半段最大收益的数组left，和右半段最大收益的数组right后，
*我们就可以遍历一遍这两个数组，找出最大的left+right组合。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1){
            return 0;
        }
        /**
        *left[i]:记录从0 到下标 i 截止 最大的profit
        *right[i]:记录从下标i截止到size()最大的profit
        */
        int* left=new int[prices.size()];
        int* right=new int[prices.size()];
        memset(left,0,sizeof(int)*prices.size());
        memset(right,0,sizeof(int)*prices.size());

        int leftMin=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<leftMin){
                leftMin=prices[i];
            }
            left[i]=max(left[i-1],prices[i]-leftMin );
        }
        int rightMax=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;--i){
            if(prices[i]>rightMax){
                rightMax=prices[i];
            }
            right[i]=max(right[i+1],rightMax-prices[i]);
        }
        int sum=0;
        for(int i=0;i<prices.size();i++){
            sum=max(sum,left[i]+right[i]);
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout<<s.maxProfit(vec)<<endl;
    vec.clear();
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(4);
    cout<<s.maxProfit(vec)<<endl;
    return 0;
}
