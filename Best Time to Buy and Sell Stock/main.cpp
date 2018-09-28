#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){
            return 0;
        }
        int minn=prices[0];
        int res=0;
        for(int i=1;i<prices.size();i++){
			//直接记录个最小值就可以了
            if(minn > prices[i]){
                minn=prices[i];
            }else{
                res=max(res,prices[i]-minn );
            }
        }
        return res;
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
