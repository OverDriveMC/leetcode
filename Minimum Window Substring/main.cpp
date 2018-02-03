#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>map(128,0);
		/**
		* 首先统计每个字符出现的次数
		*/
		for(int i=0;i<t.size();i++){
			map[t[i] ]++;
		}
		int begin=0,end=0,interval=INT_MAX;
		int head=0;
		int count=t.size();
		while(end<s.size()){
			/**
			例如： ABC
			map[A]=map[B]=map[C]=1
			假如遇到AABC
			如果map[字符串]>0 ,说明该字符串可以被包含进去,然后count--
			*/
			if(map[s[end++]]-->0){
				count--;
			}
			/**
			当count为0的时候,说明head-end之间的子串可以将t完全包含
			*/
			while(count==0){
				///每次判断字符串长度interval是否需要更新,
				///同时更新head起始位置
				if(end-begin <interval){
					interval =end-begin;
					head=begin;
				}
				/*
				从头开始往前删减字符串,如果删了一个字符串使map[字符串]的数量变成了1(++之后是1)
				说明count需要+1,这样便只能继续往后找该字符,实现count变成0,然后在进行该操作
				
				对于不存在的字符,例如D
				一开始map[D]-- >0 便是false,map[D]==0,执行完之后,会变成map[D]变成-1
				然后运行到这里的时候,map[D]++ ,因为是先判断,在+1,所以map[D]不会影响count,之前出现过多少次,最后会在加上多少次,最后变成0最多(而且是在++之后)
				所以不会影响count的值
				*/
				if( map[s[begin++]] ++==0 ){
					count++;
				}
			}
		}
		/**
		substr(startPos,count):
		   从一个字符串复制一个从指定位置开始,并具有指定长度的子字符串
		*/
		return interval==INT_MAX ? "" : s.substr(head,interval);
    }
};

int main(){
    Solution s;
    cout<<s.minWindow("abc","b")<<endl;
    cout<<s.minWindow("ABBC","ABC")<<endl;

    cout<<s.minWindow("ADOBECODEBANC","ABC")<<endl;
    return 0;
}
