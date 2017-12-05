#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool search(const vector<int>& nums, int used,int todo, int*mem,int target){
		if(mem[used]==-1){
			mem[used]=0;
			///5 1 5 2 5  2 5  1
			int targ=(todo-1) % target +1;
			char s[10];
            itoa(used, s, 2);
			printf("%s  %d\n",s,targ);
			for(int i=0;i<nums.size();i++){
				if( ((used>>i )& 1)==0 && nums[i]<=targ  ){
					if(search(nums,used | (1<<i) , todo-nums[i] , mem, target)){
						mem[used ]=1;
						break;
					}
				}
			}
		}
		return mem[used]==1;
	}

    bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum=0;
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];
		}
		if(sum%k!=0){
			return 0;
		}
		int *mem=new int[1<< nums.size() ];
		memset(mem,-1,sizeof(int)*(1<<  nums.size()));
		///初始化所有都选的情况下为1
        mem[(1 << nums.size() )- 1] = 1;
		return search(nums,0, sum, mem, sum/k);
    }
};

int main(){
    int nums[]={4,3,2,3,5,2,1};
    vector<int> vec;
    for(int i=0;i<sizeof(nums)/sizeof(int);i++){
        vec.push_back(nums[i]);
    }
    Solution s;
    printf("%d\n",s.canPartitionKSubsets(vec,4));
    return 0;
}
