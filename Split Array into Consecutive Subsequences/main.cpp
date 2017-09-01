#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()<=2){
            return false;
        }
        int start=0;
        int pos=1;
        while(pos<nums.size()){
            /**
            *假如不相邻,分别计算每一段的开始结束位置
            */
            if(nums[pos]-nums[pos-1] >1){
                if(!solve(nums,start,pos-1)){
                    return false;
                }
                start=pos;
            }
            pos++;
        }
        ///还要注意最后一段位置
        return solve(nums,start,nums.size()-1);
    }

    bool solve(vector<int>&nums,int start,int last){
        //cout<<"pos:"<<start<<"  "<<last<<endl;
        if(last-start<2){
            return false;
        }
        int len=last-start+1;
        int* fq=new int[len];
        memset(fq,0,sizeof(int)*len);
        ///将数字聚集到0-~
        for(int i=start;i<=last;i++){
            fq[nums[i]-nums[start]]++;
        }
/**
* 例如  1 2 3 4 4 5
* 统计下来为:
*    0  1   2   3   4
*    1  1   1   2   1
*  ones 记录以 i 结尾的长度为1 的数量(=fq[i]-fq[i-1])
*  twos 记录以 i 结尾的长度为2 的数量(上一轮1的数量)
*  假如  当前为 2
*  那么假如有2个 ones(以2结尾的长度为1),2的twos(以2结尾的长度为2)
*  那么必须至少有4个3可以(fq[])
**
* 这里的循环,每次都是判断当前 i 是否合法,然后将 ones 和 twos 更新到下一个位置
* 防止0要特判
*/
        int ones=fq[0];
        int twos=0;
        int lastnum=nums[last]-nums[start];
        for(int i=0;i<=lastnum;i++){
            //cout<<i<<"  "<<ones<<"  "<<twos<<" "<<fq[i+1]<<endl;
            if(fq[i+1] < ones+twos){
                return false;
            }
            twos=ones;
            ones=max(0,fq[i+1]-fq[i]);
        }
        delete[]fq;
        return true;
    }
};


int main(){
    Solution s;
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);
    cout<<s.isPossible(nums)<<endl;
    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(5);
    cout<<s.isPossible(nums)<<endl;
}
