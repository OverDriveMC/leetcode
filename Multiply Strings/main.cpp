#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        int res[250];
        memset(res,0,sizeof(res));
        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                res[i+j]+=(num1[num1.size()-1-i]-'0')*(num2[num2.size()-1-j]-'0');
            }
        }
        int len=num1.size()+num2.size();
        int carry=0;
        int temp;
        for(int i=0;i<len;i++){
            temp=res[i];
            res[i]=(temp+carry)%10;
            carry=(temp+carry)/10;
        }
        string str;
        bool flag=false;
        for(int i=len-1;i>=0;i--){
            if(!flag){
                if(res[i]!=0){
                    flag=true;
                    ///注意这里要 加 '0'
                    str.push_back(res[i]+'0');
                }
            }else{
                str.push_back(res[i]+'0');
            }
        }
        if(!flag){
            str="0";
        }
        return str;
    }
};
class Solution2 {
public:
    string multiply(string num1, string num2) {
        int res[250];
        memset(res,0,sizeof(res));
        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                int sum=(num1[num1.size()-1-i]-'0')*(num2[num2.size()-1-j]-'0');
                res[i+j+1]+=(res[i+j]+sum)/10;
                res[i+j]=(res[i+j]+sum)%10;
            }
        }
        int len=num1.size()+num2.size();
        string str;
        bool flag=false;
        for(int i=len-1;i>=0;i--){
            if(!flag){
                if(res[i]!=0){
                    flag=true;
                    ///注意这里要 加 '0'
                    str.push_back(res[i]+'0');
                }
            }else{
                str.push_back(res[i]+'0');
            }
        }
        if(!flag){
            str="0";
        }
        return str;
    }
};

int main(){
    Solution2 s;
    cout<<s.multiply("0","0")<<endl;
    cout<<s.multiply("0","10")<<endl;
    cout<<s.multiply("10","0")<<endl;
    cout<<s.multiply("10","10")<<endl;
    cout<<s.multiply("123456789","123456789")<<endl;
    return 0;
}
