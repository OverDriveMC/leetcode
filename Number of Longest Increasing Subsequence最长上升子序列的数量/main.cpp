/**
https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
输出最长上升子序列的数量
Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: 2个最长上升子序列为: [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: 最长上升子序列为1, 有5个长度为1的子序列
首先解决最长的递增序列问题,第一维dp[i].first表示长度len[i],dp[i].second表示数量ans[i]

设len[i]为以该数结尾,能构成的最长序列的长度。进行连接的时候,对于每个数字num[i],
遍历位置在它之前的数字num[j],如果比这个数小(num[j]<num[i]),也就是能
构成一个序列,这样就能进行状态转移,我们令len[i]=max(len[i],len[j]+1)来保证存储为最大长度,
同时可以记录max(dp[i])

之后考虑数量,也就是说最长长度的序列有几个,设ans[i]为第i个数结尾的最长序列的个数,
状态转移的时候,如果len更新了,也就是说(len[j]+1>len[i])说明这个长度的序列是新出现的,
需要将ans[i]设置为ans[j](用于初始化,第一次出现),因为
新序列中,最新的数提供了序列的尾巴,数量是由前面积累的(或者说转移),
例如[1 1 3 7]  当开始更新3的时候,一开始3的ans[2]=1,  而ans[0]=1         ans[0]+1>ans[2]   
所以先初始化 ans[2]=1,len[2]=len[0]+1=2

当len[j]+1==len[i]的时候,需要转移ans,  ans[i]+=ans[j]
例如[1 1 3 7], 当i=2,j=1时,  len[2]=len[1]+1, 所以 ans[2]+=ans[1]  ans[2]=2

时间复杂度为O(n^2)
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int max_len=0,res=0;
        vector<pair<int,int>>dp(nums.size(), {1,1});
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]>nums[j]) {
                    if(dp[i].first== dp[j].first+1) {
						//之后直接将数量加上即可
                        dp[i].second+=dp[j].second;
                    }
                    if(dp[i].first<dp[j].first+1) {
						//第一次用于初始化,同时将最长上升子序列长度更新
                        dp[i]= {dp[j].first+1, dp[j].second};
                    }
                }
            }
			//出现多个相同的最长上升子序列[2 2 2 2]需要加在一起
            if(max_len==dp[i].first) {
                res+=dp[i].second;
            } else if(max_len< dp[i].first) {
                max_len=dp[i].first;
                res=dp[i].second;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums= {1,3,5,4,7};
    cout<<s.findNumberOfLIS(nums)<<endl;
    return 0;
}
