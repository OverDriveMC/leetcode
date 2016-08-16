#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    ///'(', ')', '{', '}', '[' and ']'
    ///"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='(' ){
                st.push(s[i]);
            }else if(s[i]==')'){
                if(st.empty()){
                    return false;
                }
                char top=st.top();
                if(top=='('){
                    st.pop();
                }else{
                    return false;
                }
            }else if(s[i]==']'){
                if(st.empty()){
                    return false;
                }
                char top=st.top();
                if(top=='['){
                    st.pop();
                }else{
                    return false;
                }
            }else if(s[i]=='}'){
                if(st.empty()){
                    return false;
                }
                char top=st.top();
                if(top=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.size()==0 ? true : false;
    }

};


int main(){
    Solution s;
    cout<<s.isValid("]")<<endl;
    cout<<s.isValid("([])")<<endl;
    cout<<s.isValid("()()[]{}{")<<endl;
    cout<<s.isValid("([)]")<<endl;
    return 0;
}
