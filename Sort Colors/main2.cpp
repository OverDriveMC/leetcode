#include<bits/stdc++.h>

using namespace std;

/**
遍历,每次遇到0将之交换到validZPos的位置,同时validZPos往后移一位
每次遇到2将之交换到validTPos的位置,同时validTPos往前移一位
注意：最后截止位置i <= validTPos,否则会将2在交换回去。
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int validZPos=0;
        int validTPos=nums.size()-1;
		int i=0;
		/**
		每次循环的时候,要么i变,或者validTPos需要变化,否则会死循环
		当nums[i]==0时,因为不会影响到validTPos,所以i必须往后移动
		nums[i]==2时,会使validTPos往前移动一位
		*/
		while(i<=validTPos){
			if(nums[i]==0){
                swap(nums[i],nums[validZPos]);
				//这里需要i往后移动
				//因为只要是0,总会把它交换到0-validZPos的范围内,所以这里可以往后加
                i++;
                validZPos++;
			}else if(nums[i]==2){
				///但是为2的时候,如果i也往后移动的话,会同时动两个位置
				/**
				1 2 0
				1 0 2 这样会直接退出去
				*/
                swap(nums[i],nums[validTPos]);
                validTPos--;
			}else{
                i++;
			}
		}
    }
};


int main(){
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(2);

    Solution s;
    s.sortColors(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    cout<<endl<<endl;
    vec.clear();
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);
    s.sortColors(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
