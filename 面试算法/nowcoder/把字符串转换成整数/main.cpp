/**
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
		输入一个字符串,包括数字字母符号,可以为空
输出描述:
		如果是合法的数值表达则返回该数字，否则返回0
示例1
	输入
			+2147483647
			1a33
	输出
			2147483647
			0

*/
class Solution {
public:
    int StrToInt(string str) {
        long res=0;
        int sign=-1;
        for(int i=0;i<str.size();i++){
            if(str[i]>='0' && str[i]<='9'){
                res=res*10+(str[i]-'0'); 
            }else if(i==0){
                if(str[i]=='+'){
                    sign=1;
                }else if(str[i]=='-'){
                    sign=0;
                }
            }else{
                return 0;
            }
        }
        return sign==0 ? (-res<INT_MIN ? 0 : -res ) : (res> INT_MAX ? 0 : res );
    }
};