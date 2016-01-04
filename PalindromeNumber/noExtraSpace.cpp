#include<bits/stdc++.h>
using namespace std;
/**
*需要考虑负数
*如果考虑reverse number的方法，可能造成溢出。
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int temp=x;
        int count=0;
        while(temp){
            count++;
            temp/=10;
        }
        temp=x;
        int pow=1;
        for(int i=0;i<count-1;i++){
            pow*=10;
        }
        for(int i=0;i<count/2;i++){
            /**
            * 12345/10000=1
            * 12345/1000=12 12%10=2
            * 依次从高位开始取
            * 后面的x每次取最低位
            */
            if(temp/pow%10 != x%10  ){
                return false;
            }
            x/=10;
            pow/=10;
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
