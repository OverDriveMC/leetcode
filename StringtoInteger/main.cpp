#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        ///去掉前导空格与后面的空格
        str=trim(str);
        if(str.length()<=0){
            return 0;
        }

        const long long maxn=0x7fffffff;
        const long long minn=0x80000000;
        long long res=0;
        int firstpos=0;
        int cnt=0;
        bool positive=true;
        ///判断是否为负数
        if(str[0]=='-'){
            cnt=1;
            positive=false;
        }else if(str[0]=='+'){
            cnt=1;
        }else{
            cnt=0;
        }
        bool flag=true;
        while(cnt<str.length()){
            int temp=str[cnt++]-'0' ;
            ///不合法字符
            ///不合法字符输出的为前面的合法字符
            if(temp <0 || temp >9){
                break;
            }

            res*=10;
            res+=temp;
            ///溢出 分别输出最大值或最小值
            if(res>maxn && positive){
                return maxn;
            }else if(res> minn && !positive){
                return 0-minn;
            }
        }


        if(positive){
            return res;
        }else{
            return 0-res;
        }
    }

    string trim(string str){
        int firstpos=0,lastpos=-1;
        int cnt=0;
        while(str[cnt]==' '){
            cnt++;
        }
        firstpos=cnt;
        cnt=str.length()-1;
        while(str[cnt]==' '){
            cnt--;
        }
        lastpos=cnt;
        if(lastpos<firstpos){
            return "";
        }else{
            return str.substr(firstpos,lastpos-firstpos+1);
        }
    }
};


int main(){
    Solution s;
    cout<<s.myAtoi("  -0012a42")<<endl;
    cout<<s.myAtoi("    010")<<endl;
    cout<<s.myAtoi("+100")<<endl;
    cout<<s.myAtoi("100")<<endl;
    cout<<s.myAtoi("-100")<<endl;
    return 0;
}
