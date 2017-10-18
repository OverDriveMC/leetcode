#include<bits/stdc++.h>

using namespace std;
/**
创建一个数组days[]记录每个位置的花开的时间
days[i]记录在位置i+1的话开的时间
flowers={1,3,2}
第1天开的花在位置1
第3天开的花在位置2
第2天开的花在位置3
days={1,3,2};
位置1的花在第1天开
位置2的花在第3天开
位置3的花在第2天开
之后只要找子数组
	day[left,left+1,...,left+k-1,right]满足:
		i=left+1,...,left+k-1   =>days[left]<days[i]  && days[right] <days[i]
	那么结果便是max(days[left],days[right])
*/


class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
		int *days=new int[flowers.size()];
		for(int i=0;i<flowers.size();i++){
			days[flowers[i]-1 ] =i+1;
		}
		int left=0,right=k+1,res=INT_MAX;
/*
		for(int i=0;i<flowers.size();i++){
            cout<<days[i]<<"  ";
		}
		cout<<endl;
*/

		for(int i=1; right<flowers.size();i++){
			if(i==right){
				res=min(res,max(days[left],days[right]));
			}
			if(days[i]<=days[left] || days[i]<=days[right] ){
				left=i;
				right=i+k+1;
			}
		}
		return res==INT_MAX ?-1 : res;
    }
};

int main(){
    vector<int>vec;
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(10);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(7);
    Solution s;
    cout<<s.kEmptySlots(vec,1)<<endl;
	return 0;
}
