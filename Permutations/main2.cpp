/*
当n=1时，数组中只有一个数a1，其全排列只有一种，即为a1

当n=2时，数组中此时有a1a2，其全排列有两种，a1a2和a2a1，那么此时我们考虑和上面那种情况的关系，我们发现，其实就是在a1的前后两个位置分别加入了a2

当n=3时，数组中有a1a2a3，此时全排列有六种，分别为a1a2a3, a1a3a2, a2a1a3, a2a3a1, a3a1a2, 和 a3a2a1。那么根据上面的结论，实际上是在a1a2和a2a1的基础上
在不同的位置上加入a3而得到的。

_ a1 _ a2 _ : a3a1a2, a1a3a2, a1a2a3

_ a2 _ a1 _ : a3a2a1, a2a3a1, a2a1a3


*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		if(nums.empty()){
			return vector<vector<int> >(1,vector<int>() );
		}
		vector<vector<int> >res;
		int first=nums[0];
		nums.erase(nums.begin());
		vector<vector<int> >words=permute(nums);
		for(auto & a : words ){
			for(int i=0;i<=a.size();i++){
				a.insert(a.begin()+i, first);
				res.push_back(a);
				a.erase(a.begin()+i);
			}
		}
		return res;
    }
};

/**
first=1                               first=2                   first=3
nums=[2 3] 							  nums=[3]                  nums=[]
                                                           res=[[3] ]
                                      a=[3]
									  res=[[2,3] ,[3,2]] 
a=[2,3] => [1,2,3] [2,1,3] [2,3,1]
a=[3,2] => [1,3,2] [3 1 2]  [3 2 1]
 */