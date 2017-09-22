#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int pos=0;
		stack<int>num;
		stack<char>op;
		while(pos<s.size()){
           // cout<<"pos:"<<pos<<"  "<<s[pos]<<endl;
			if(s[pos]==' '){
				pos++;
				continue;
			}
			if(s[pos]<='9' && s[pos]>='0'){
				int temp=0;
				while(pos<s.size() && s[pos]<='9' && s[pos]>='0' ){
					temp=temp*10 + (s[pos++]-'0');
				}
				num.push(temp);
			}else if(s[pos]=='+'){
				op.push(s[pos]);
				pos++;
			}else if(s[pos]=='-'){
			    int temp=0;
			    pos++;
			    while(pos<s.size() && s[pos]==' ' ){
                    pos++;
                }
				while(pos<s.size() && s[pos]<='9' && s[pos]>='0' ){
					temp=temp*10 + (s[pos++]-'0');
				}
				num.push(-temp);
			}else if(s[pos]=='*'){
				pos++;
				int val1=0;
				while(pos<s.size() && s[pos]==' ' ){
                    pos++;
                }
				while(pos<s.size() && s[pos]<='9' && s[pos]>='0'){
					val1=val1*10 + (s[pos++]-'0');
				}
				int val2=num.top();
				//cout<<"*"<<val1<<"  "<<val2<<endl;
				num.pop();
				num.push(val1 * val2);
			}else{
				pos++;
				int val1=0;
                while(pos<s.size() && s[pos]==' ' ){
                    pos++;
                }
				while(pos<s.size() && s[pos]<='9' && s[pos]>='0'){
					val1=val1*10 + (s[pos++]-'0');
				}
				int val2=num.top();
				num.pop();
				//cout<<"/"<<val1<<"  "<<val2<<endl;
				num.push( val2 / val1);
			}
		}
        int result=0;
		while(!num.empty()){
			int val=num.top();
			num.pop();
			result+=val;
		}
		//cout<<"size:"<<num.size()<<endl;
		return result;
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
