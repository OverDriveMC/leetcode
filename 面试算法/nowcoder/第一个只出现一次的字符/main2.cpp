class Solution {
public:
/**
直接存储数量,在遍历一遍字符串即可
*/
    int FirstNotRepeatingChar(string str) {
        map<char,int>times;
        for(int i=0;i<str.size();i++){
            times[str[i]]++;
        }
        int minIndex=str.size();
        for(int i=0;i<str.size();i++){
            if(times[str[i]]==1){
                return i;
            }
        }
        return -1;
    }
};