/**
假设字符串abcdef,n=3
令X=abc  Y=def
所以字符串可以表示成XY,题目即要求求得YX
假设X的翻转为X^T, X^T=cba
同理Y的翻转为Y^T, Y^T=fed
那么YX=(X^TY^T)^T 三次翻转即可得到结果
*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len=str.size();
        if(len==0){
            return str;
        }
        n%=len;
        for(int i=0,j=n-1;i<j;i++,j--) swap(str[i],str[j]);
        for(int i=n,j=len-1;i<j;i++,j--) swap(str[i],str[j]);
        for(int i=0,j=len-1;i<j;i++,j--) swap(str[i],str[j]);
        return str;
    }
};

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len=str.size();
        if(len==0){
            return str;
        }
        n%=len;
		//这种交换要注意/2
        for(int i=0;i<n/2;i++) swap(str[i],str[n-i-1]);
        for(int i=n;i<n+(len-n)/2;i++) swap(str[i],str[len-i+n-1]);
        for(int i=0;i<len/2;i++) swap(str[i],str[len-i-1]);
        return str;
    }
};