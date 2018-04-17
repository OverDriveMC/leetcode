/**
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

*/

/**
对vector容器内的数据进行排序，按照 将a和b转为string后
 若 a＋b<b+a  a排在在前 的规则排序,
 如 2 21 因为 212 < 221 所以 排序后为 21 2 
  to_string() 可以将int 转化为string
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	/**
	注意比较函数写在类内的时候要加上static
	*/
    static bool cmp(int a,int b){
		/**
		* 采用ostringstream拼接字符串
		*/
        ostringstream ab;
        ab<<a<<b;
        ostringstream ba;
        ba<<b<<a;
        return ab.str()<ba.str();
    }
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(),numbers.end(),cmp);
        ostringstream oss;
        for(int i=0;i<numbers.size();i++){
            oss<<numbers[i];
        }
        return oss.str();
    }
};

int main(){
    int a[]={3,321,32};
    Solution s;
    cout<<s.PrintMinNumber(vector<int>(a,a+3))<<endl;
    return 0;
}
