#include<bits/stdc++.h>
using namespace std;
/**
*��Ҫ���Ǹ���
*�������reverse number�ķ�����������������
*/
class Solution {
public:
    bool isPalindrome(int x) {
        string s;
        if(x<0){
            return false;
        }
        while(x){
            s+=(x%10)+'0';
            x/=10;
        }
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isPalindrome(0)<<endl;
    cout<<s.isPalindrome(00)<<endl;
    cout<<s.isPalindrome(100)<<endl;
    cout<<s.isPalindrome(12)<<endl;
    return 0;
}
