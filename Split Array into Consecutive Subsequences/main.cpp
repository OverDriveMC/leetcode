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
            if(nums[pos]-nums[pos-1] >1){
                if(!solve(nums,start,pos-1)){
                    return false;
                }
                start=pos;
            }
            pos++;
        }
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
