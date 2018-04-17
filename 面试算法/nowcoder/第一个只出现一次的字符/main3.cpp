class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        for(int i=0;i<str.size();i++){
			//正着倒着搜到的位置一样,说明只有一个
            if(str.find(str[i] ) ==str.rfind(str[i]) ){
                return i;
            }
        }
        return -1;
    }
};