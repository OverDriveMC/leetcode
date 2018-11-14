/**
https://leetcode.com/problems/burst-balloons/description/
题意：给一串气球,每个气球上都标了一个数字,这些数字用一个数组nums来表示,如果扎破第i个气球,
就可以获得nums[left] * nums[i] * nums[right] 个硬币, 其中left和right是与第i个气球相邻的两个气球,
当i被扎破后,left和right就变成直接相邻了,找出一个扎破所有气球的顺序,使得最后获得的硬币数量的总和最大
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
借鉴了矩阵连乘的求解思路,
首先：考虑将问题分解成一个或多个子问题，假设第i个气球是第一个扎破的气球,可以得到
nums[i-1] * nums[i] *nums[i+1] + maxCoins(int[]newNums)个硬币,其中newNums表示的是删掉nums[i]后由数组nums中
剩余元素构成的新数组,如果以这个顺序来分解问题,我们每次都要重新调整数组的结构,并且在这种分解顺序下,原问题
和子问题都难以用简洁的标识符来表示。换一种方式考虑：
如果假设第i个气球是最后一个扎破的气球,剩下的气球不管是以什么样的顺序扎破,
位于第i个气球的左边的所有气球,他们的right值只可能小于等于i
而位于第i个气球右边的所有气球，他们的left值只可能大于等于i
因此,如果第i个气球最后扎破,那么它左右两边的气球扎破顺序可以分开来求
(按任何顺序扎破左半边所有的气球都不会影响右半边的最大值,右半边同理)
dp[i][j]表示打爆[i,j]中的所有气球能得到的最多金币,题目中说明了边界情况,当气球周围没有气球的时候
旁边的数字按1算,这样可以在原数组两边各填充一个1,便于计算,
递推式：
dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1]+ dp[k+1][j]   ) (i<=k<=j)
k=i时 nums[i-1]*nums[i]*nums[j+1] + dp[i][i-1] + dp[i+1][j]
k=j时 nums[i-1]*nums[j]*nums[j+1] + dp[i][j-1] + dp[j+1][j]
dp[i][k-1]表示i到k-1的气球都被扎破了,所以左边的气球是i-1
dp[k+1][j]表示k+1到j的气球都被扎破了,所以右边的气球是j+1
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1,0));
        for(int len=1;len<=nums.size()-2;len++){
            for(int i=1;i<nums.size()-len;i++){
                int j=i+len-1;
                for(int k=i;k<=j;k++){
					/**
					当len=1的时候,i= [1,nums.size()-1)
					    i==j      j= [1, nums.size()-1)
					k=i
					dp[i][i]=dp[i][i-1] + dp[i+1][i] + nums[i-1]*nums[i]*nums[i+1]
					也符合题意
					*/
                    dp[i][j]=max(dp[i][j] , dp[i][k-1]+dp[k+1][j]+ nums[i-1]*nums[k]*nums[j+1] );
                }
            }
        }
        return dp[1][nums.size()-2];
    }
};


int main(){
    Solution s;
    vector<int>nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(8);
    cout<<s.maxCoins(nums)<<endl;
}
