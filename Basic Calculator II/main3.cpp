#include<bits/stdc++.h>

using namespace std;

/**
* 乘除 算完结果添加进去
* + -则是把数存入栈里,最后统一为加法操作
*/
class Solution {
public:
    int calculate(string s) {
        //cout<<s<<endl;
        char sign='+';
        stack<int>st;
        int pos=0;
        int num=0;
        while(pos<s.size()){
            if(isdigit(s[pos])){
                num=num*10+(s[pos]-'0');
            }
			///当不是数字,并且不是空格的时候进入循环
			///或者是到最后一轮的时候进入(一定要判断最后一个位置)
            if( (!isdigit(s[pos]) && s[pos]!=' ')  || pos==(s.size()-1)){
                //cout<<pos<<"  "<<s.size()<<endl;
                if(sign=='+'){
                    st.push(num);
                }else if(sign=='-'){
                    st.push(-num);
                }else if(sign=='*'){
                    int val=st.top();
                    st.pop();
                    st.push(val * num);
                }else if(sign=='/'){
                    int val=st.top();
                    st.pop();
                    st.push(val / num);
                }
				///下次采用的sign是前一轮的,但是判断是否进入是用的当前的
                sign=s[pos];
                num=0;
            }
            pos++;
        }
        while(!st.empty()){
            num+=st.top();
            st.pop();
        }
        return num;
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
