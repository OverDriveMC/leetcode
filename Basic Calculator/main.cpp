#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        //cout<<s<<endl;
        stack<char>st;
		stack<char>op;
		int pos=0;
		int result=0;
		while(pos<s.size()){
            if(s[pos]==' '){
                pos++;
                continue;
            }
			if(s[pos]!=')'){
				st.push(s[pos]);
			}else{
				while(!st.empty()){
					if(st.top()=='('){
                        st.pop();
                        break;
					}
					op.push(st.top());
					st.pop();
				}
				result=calc(op);
                if(result<0){
                    result=-result;
                    st.push('-');
                }else if(result==0){
                    /**
                    * 注意,等于0的时候要特判,否则while拆分每一位的时候,0加不进去
                    */
                    st.push('0');
                }
				stack<char>t;
				while(result){
                    t.push(result%10 +'0');
                    result/=10;
				}
				while(!t.empty()){
                    st.push(t.top());
                    t.pop();
				}
			}
			pos++;
		}
		while(!st.empty()){
			if(st.top()=='('){
                st.pop();
                break;
            }
            op.push(st.top());
            st.pop();
		}
		result=calc(op);
		return result;
    }
    void print(stack<char>op){
        while(!op.empty()){
            cout<<op.top()<<"  ";
            op.pop();
        }
        cout<<endl;
    }

    ///注意要引用传值
	int calc(stack<char>&op){
	    //print(op);
        ///先取一个数,防止是单括号,里面有一个数的情况
		int result=0;
		while(!op.empty() && op.top()<='9' && op.top()>='0'){
			result=result*10+(op.top()-'0');
			op.pop();
		}
		while(!op.empty()){
			char opc=op.top();
			op.pop();
			if(opc=='+'){
                int flag=1;
                ///因为上次算出来的可能是负数,要算前面有几个减号
			    while(!op.empty() && op.top()=='-' ){
                    flag=-flag;
                    op.pop();
			    }
				int temp=0;
				while(!op.empty() && op.top()<='9' && op.top()>='0'){
					temp=temp*10+(op.top()-'0');
					op.pop();
				}
				result+=temp*flag;
			}else if(opc=='-'){
			    int flag=-1;
			    ///因为上次算出来的可能是负数,要算前面有几个减号
			    while(!op.empty() && op.top()=='-' ){
                    flag=-flag;
                    op.pop();
			    }
				int temp=0;
				while(!op.empty() && op.top()<='9' && op.top()>='0'){
					temp=temp*10+(op.top()-'0');
					op.pop();
				}
				result+=temp*flag;
			}
		}
		return result;
	}

};


int main(){
	Solution s;
	cout<<s.calculate("1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10")<<endl;
	cout<<s.calculate("2-(5-6)")<<endl;
	cout<<s.calculate(" 30")<<endl;
	cout<<s.calculate("2-1+2")<<endl;
	cout<<s.calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
}
