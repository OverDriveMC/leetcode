class Solution {
public:
	/**
	* index代表当前遍历到的元素
	* 需要做处理的元素
	*/
    void dfs(const vector<int>&nums,int index, vector<int>cur, vector<vector<int> >&res ){
        if(index==nums.size()){
            res.push_back(cur);
            return ;
        }
        //两种情况,一种是不添加当前元素
        dfs(nums,index+1, cur, res);
        cur.push_back(nums[index]);
		///一种是添加当前元素
        dfs(nums,index+1, cur, res);
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        vector<vector<int>>res;
        dfs(nums,0,vec,res);
        return res;
    }
};