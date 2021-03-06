/*
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxn=array[0];
        int cursum=maxn;
        for(int i=1;i<array.size();i++){
            cursum=max(cursum+array[i],array[i]);
            maxn=max(maxn,cursum);
        }
        return maxn;
    }
};