/**
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //注意,还要判断k是否等于0
        if(k==0 || input.size()<k){
            return vector<int>();
        }
        vector<int>res(input.begin(),input.begin()+k);
        make_heap(res.begin(),res.end());
        for(int i=k;i<input.size();i++){
            if(input[i]<res[0]){
                pop_heap(res.begin(),res.end());
                res.pop_back();
                res.push_back(input[i]);
                push_heap(res.begin(),res.end());
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};