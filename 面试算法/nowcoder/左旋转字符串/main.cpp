/**
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len=str.size();
        if(len==0){
            return str;
        }
		//n可能比len长
        n=n%len;
        str+=str;
		//开始位置,长度
        return str.substr(n,len);
    }
};