#include<bits/stdc++.h>

using namespace std;
///括号的位置
class Parenthese{
public:
    int index;
    char symb;
    Parenthese(int index,char symb):index(index),symb(symb){}
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<Parenthese>st;
        int maxn=0;
        for(int i=0;i<s.size();i++){
            ///假如是(,直接入栈
            if(s[i]=='('){
                st.push(Parenthese(i,'('));
            }else{
                ///当栈不为空的时候,并且栈顶元素为(
                if(!st.empty() && st.top().symb=='('){
                    int curlength=0;
                    st.pop();
                    ///假如栈为空,说明之前所有的字符是一个完整的合法的括号序列
                    if(st.empty()){
                        curlength=i+1;
                    }else{
                        ///假如栈不为空,那么合法的字符序列为从当前栈顶元素的位置到当前遍历的位置
                        curlength=i-st.top().index;
                    }
                    maxn=max(maxn,curlength);
                }else{
                    ///说明栈顶为空或者栈顶元素为),无法匹配,压入栈占位,保证后面的可以正常匹配(这些元素不存在出栈的可能性了)
                    st.push(Parenthese(i,')'));
                }
            }
        }
        return maxn;
    }
};

int main(){
    Solution s;
    cout<<s.longestValidParentheses(")()())")<<endl;
    cout<<s.longestValidParentheses("()()")<<endl;
    cout<<s.longestValidParentheses("(((())))")<<endl;
    cout<<s.longestValidParentheses("))")<<endl;
    cout<<s.longestValidParentheses("(()())")<<endl;
    return 0;
}
