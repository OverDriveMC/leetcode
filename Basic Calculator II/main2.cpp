#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
		///首尾加上两个 +
        istringstream in('+' + s +'+');
        int total=0,term=0;
        int n;
        char op;
        while(in>>op){
			///判断当前操作符是否为 + 或 -
			///假如是,将前一个计算的term加入
            if(op=='+' || op=='-'){
                total+=term;
				///读入当前的term,并判断符号
                in>>term;
                term=op=='+' ? term : -term;
            }else{
				///前一个操作数为term,符号后面的操作数为n
                in>>n;
                if(op=='*'){
                    term*=n;
                }else if(op=='/'){
                    term/=n;
                }
            }
        }
        return total;
    }
};

int main(){
	Solution s;
	cout<<s.calculate("3+2*2")<<endl;
	cout<<s.calculate(" 3/2 ")<<endl;
	cout<<s.calculate(" 3+5 / 2 ")<<endl;
	cout<<s.calculate(" 1 -2 + 3 ")<<endl;
	return 0;
}