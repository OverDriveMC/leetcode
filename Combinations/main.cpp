class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
		vector<vector<int> >res;
		if(n<k){
			return res;
		}
		vector<int>temp;
		dfs(n,k,res,temp,1);
        return res;
    }
	void dfs(int n,int k, vector<vector<int> >&res, vector<int>&temp,int start){
		if(temp.size()==k){
			res.push_back(temp);
			return ;
		}
		for(int i=start;i<=n;i++){
			/**
			*接下来从i+1开始搜索,每次添加的数都比当前的大,所以
			*不需要采用vis判重
			*/
			temp.push_back(i);
			dfs(n,k,res,temp,i+1);
			///删除末尾元素pop_back()
			temp.pop_back();
		}
	}
	
};