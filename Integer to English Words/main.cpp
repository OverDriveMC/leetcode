/**
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
生成英文表示
注意:这里是非负的(面试时记得询问下数据范围)
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
/**
定义string数组时,貌似必须指明大小
对象成员只能在构造函数的初始化列表里初始化
*/
    string below_10[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    string below_20[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string below_100[8]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

    const int billion=1e9;
    const int million=1e6;
    const int thousand=1e3;
    const int hundred=1e2;

    string numberToWords(int num) {
        if(num==0){
            return below_10[0];
        }
		/**
		在开头补一个空格,然后最后在删掉最前面的空格
		*/
        return int_string(num).substr(1);
    }
	/**
	因为无论后面的单位是多少,都能保证它最后往里加的时候  是一个十位数
	1 234 567 890
	One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety
	先得到billion===>是一个1,然后int_string(1) 得到  " One" 接着根上" Billion" + int_string(234 567 890)  ========>" One Billion"
	接着得到======> int_string(234)  ===> int_string(2)+" Hundred"  ======>" Two Hundred"=======>" One Billion Two Hundred"
	                                          +int_string(34)====>" Thirty Four"       =====>" One Billion Two Hundred Thirty Four Million"
	接着计算int_string(567 890) ====> int_string(567)+" Thousand"   =======>" One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand"  
				int_string(567)====>" Five Hundred Sixty Seven"  
	最后计算int_string(890)    ======>" Eight Hundred Ninety"
	综合得到" One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety" 最后去掉开头空格
	*/
    string int_string(int num){
       // cout<<num<<endl;
        if(num>=billion){
            return int_string(num/billion) +" Billion"+int_string(num%billion);
        }if(num >= million ){
            return int_string(num/million) +" Million"+ int_string(num%million);
        }else if(num>=thousand){
            return int_string(num/thousand) +" Thousand" + int_string(num%thousand);
        }else if(num>=hundred){
            return int_string(num/hundred) +" Hundred" + int_string(num%hundred);
        }else if(num>=20){
            return string(" ")+below_100[num/10 -2]+int_string(num%10);
        }else if(num>=10){
            return string(" ")+below_20[num-10];
        }else if(num>0){
            return string(" ")+below_10[num];
        }else{
            return "";
        }
    }
};



class Solution2 {
public:
    static string numberToWords(int n) {
        if(n == 0) return "Zero";
        else return int_string(n).substr(1);
    }
private:
    static const char * const below_20[];
    static const char * const below_100[];
    static string int_string(int n) {
        if(n >= 1000000000)   return int_string(n / 1000000000) + " Billion" + int_string(n - 1000000000 * (n / 1000000000));
        else if(n >= 1000000) return int_string(n / 1000000) + " Million" + int_string(n - 1000000 * (n / 1000000));
        else if(n >= 1000)    return int_string(n / 1000) + " Thousand" + int_string(n - 1000 * (n / 1000));
        else if(n >= 100)     return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
        else if(n >= 20)      return string(" ") + below_100[n / 10 - 2] + int_string(n - 10 * (n / 10));
        else if(n >= 1)       return string(" ") + below_20[n - 1];
        else return "";
    }
};

const char * const Solution2::below_20[] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char * const Solution2::below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
int main(){
    Solution s;
    cout<<s.numberToWords(1234567890)<<endl;
    cout<<s.numberToWords(1234567891)<<endl;
    cout<<s.numberToWords(12345)<<endl;
    cout<<s.numberToWords(1234567)<<endl;
    return 0;
}
