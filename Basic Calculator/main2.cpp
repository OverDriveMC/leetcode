#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
		///nums存储括号前计算的结果,ops存储括号前的标志位 + 1  - -1
        stack<int>nums,ops;
		int sign=1,rst=0;
		int pos=0;
		int num=0;
		while(pos<s.size()){
			if(isdigit(s[pos])){
				num=num*10+(s[pos]-'0');
			}else{
				rst+=num*sign;
				num=0;
				if(s[pos]=='+') { sign=1; }
				else if(s[pos]=='-') {sign=-1;}
				else if(s[pos]=='('){
				///这里push进去的结果,在遇到 )的时候马上便会出栈
				///存储括号(前的计算结果以及符号
					nums.push(rst);
					ops.push(sign);
					rst=0;
					sign=1;
				}else if(s[pos]==')'){
				    ///计算()和前一个数的结果
					rst= nums.top() + ops.top() * rst;
					ops.pop();
					nums.pop();
				}
			}
			pos++;
		}
		//栈内在遇到)之后始终为空
		///防止最后一个出现的数字没有计算 2-1+2
		rst+=sign * num;
		return rst;

    }
};


int main(){
	Solution s;
	cout<<s.calculate("1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10")<<endl;
	cout<<s.calculate("2-(5-6)")<<endl;
	cout<<s.calculate(" 30")<<endl;
	cout<<s.calculate("2-1+2")<<endl;
	cout<<s.calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
	return 0;
}
