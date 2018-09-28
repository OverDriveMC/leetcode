/**
给定一系列非负整数,合并成为一个最大的数
Input: [10,2]
Output: "210"
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
		/**
		a+b > b+a
		进行排序
		*/
        sort(nums.begin(),nums.end(),[](int & a,int&b){ return to_string(a)+to_string(b)>to_string(b)+to_string(a); } );
        string res;
        for(int i=0;i<nums.size();i++){
            res+=to_string(nums[i]);
        }
		//假如结果是0,需要去掉前导0
        if(res.size()>0 && res[0]=='0'){
            return "0";
        }else{
            return res;
        }
    }
};
