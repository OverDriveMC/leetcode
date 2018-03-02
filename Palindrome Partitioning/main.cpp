class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>cur;
        dfs(res,0, s, cur);
        return res;
    }
	/**
	*  表示从s的第pos个字符串开始搜索新的回文串
	*      cur里装的是pos之前形成的回文串
	*/
    void dfs(vector<vector<string>>&res, int pos,string&s, vector<string>&cur){
		///如果pos到达了s.size(),说明正好全部分成回文串,否则变没有,只有到达s.size()的时候才是全部分为回文串
        if(pos==s.size()){
            res.push_back(cur);
            return ;
        }
        for(int i=pos;i<s.size();i++){
			//每次枚举从pos到i之间的回文串
            if(isPalindrome(s,pos,i)){
				///假如是回文串,添加到cur中
                cur.push_back(s.substr(pos, i-pos+1));
                dfs(res,i+1,s,cur);
				///删除刚刚添加的回文串,开始枚举pos到下一个i能形成回文串的分割
                cur.erase(cur.end()-1);
            }
        }
    }
    bool isPalindrome(const string &s,int low,int high){
        while(low<high){
            if(s[low++]!=s[high--]){
                return false;
            }
        }
        return true;
    }
};