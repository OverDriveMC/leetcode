/**
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int>times;
        map<char,int>idx;
        for(int i=0;i<str.size();i++){
            if(idx.find(str[i])==idx.end()){
				/**
				map的插入
				*/
                idx.insert(make_pair(str[i],i));
                times.insert(make_pair(str[i],1));
            }else{
                times[str[i] ]++;
            }
        }
        int minIndex=str.size();
		/**
		map的遍历
		*/
        for(map<char,int>::iterator iter=idx.begin();iter!=idx.end(); iter++){
            if(times[iter->first ]==1 ){
                minIndex=min(minIndex, iter->second);
            }
        }
        return minIndex==str.size() ? -1 : minIndex;
    }
};