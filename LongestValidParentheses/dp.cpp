#include<bits/stdc++.h>

using namespace std;
/**
*dp[i]����ӿ�ͷ���±�i�ĺϷ�������ƥ������
*(***) ����s[i]�� ')',��ô��ǰ���� start=i-dp[i-1]-1 (ȥ��dp[i-1]�ĺϷ�����ƥ��),������'(',��ô˵��[start,i]
*��һ�κϷ�����,dp[i]=dp[i-1]+2
*ͬʱ,���� start-1û��Խ��,��ô���κϷ�����ƥ����Ժϲ�(���뵱ǰ��Ҫ�ǺϷ���,֮ǰ��Ҳ�ǺϷ��Ĳ��ܺϲ�)
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<=1){
            return 0;
        }
        int *dp=new int[s.size()];
        int maxn=0;
        memset(dp,0,sizeof(int)*s.size());
        for(size_t i=1;i<s.size();i++){
            if(s[i]==')'){
                int start=i-1-dp[i-1];
                if(start>=0 && s[start]=='('){
                    dp[i]=dp[i-1]+2;
                    ///ifҪ�������ڲ�,Ҫ��֤��ǰ�κϷ����ܺϲ�
                    if((start-1)>=0){
                        dp[i]+=dp[start-1];
                    }
                }
            }
            maxn=max(dp[i],maxn);
        }

        delete[]dp;
        return maxn;
    }
};

int main(){
    Solution s;
    cout<<s.longestValidParentheses("()()))))()()(")<<endl;
    cout<<s.longestValidParentheses("())")<<endl;
    cout<<s.longestValidParentheses(")()())")<<endl;
    cout<<s.longestValidParentheses("()()")<<endl;
    cout<<s.longestValidParentheses("(((())))")<<endl;
    cout<<s.longestValidParentheses("))")<<endl;
    cout<<s.longestValidParentheses("(()())")<<endl;
    return 0;
}
