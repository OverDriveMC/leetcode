#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,level=0,water=0;
        while(l<r){
            ///注意,取得是++与--之前的值,即每次选左右两边小的那个数,
            ///在另一边可以保证一定有不小于当前数的数,所以一定能形成凹字形。
            int lower=height[height[l]<height[r]? l++ : r-- ];
            ///拿这个值与当前维护的最大值比较,小于的话,则说明此地可以填水,否则,更新level.
            level=max(level,lower);
            water+=level-lower;
        }
        return water;
    }
};

int main(){
    Solution s;
    vector<int>height;
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);
    cout<<s.trap(height)<<endl;
    return 0;
}
