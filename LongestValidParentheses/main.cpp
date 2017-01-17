#include<bits/stdc++.h>

using namespace std;
///���ŵ�λ��
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
            ///������(,ֱ����ջ
            if(s[i]=='('){
                st.push(Parenthese(i,'('));
            }else{
                ///��ջ��Ϊ�յ�ʱ��,����ջ��Ԫ��Ϊ(
                if(!st.empty() && st.top().symb=='('){
                    int curlength=0;
                    st.pop();
                    ///����ջΪ��,˵��֮ǰ���е��ַ���һ�������ĺϷ�����������
                    if(st.empty()){
                        curlength=i+1;
                    }else{
                        ///����ջ��Ϊ��,��ô�Ϸ����ַ�����Ϊ�ӵ�ǰջ��Ԫ�ص�λ�õ���ǰ������λ��
                        curlength=i-st.top().index;
                    }
                    maxn=max(maxn,curlength);
                }else{
                    ///˵��ջ��Ϊ�ջ���ջ��Ԫ��Ϊ),�޷�ƥ��,ѹ��ջռλ,��֤����Ŀ�������ƥ��(��ЩԪ�ز����ڳ�ջ�Ŀ�������)
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
