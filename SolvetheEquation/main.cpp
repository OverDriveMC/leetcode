#include<bits/stdc++.h>
#include<sstream>
using namespace std;

class Solution {
public:
    ///返回结束位置
    int mysearch(string equation,int &xnum,int& sum,int startPos) {
        for(int i=startPos; i<equation.size();) {
            //cout<<i<<"   "<<equation.size()<<endl;
            if(equation[i]=='=') {
                return i;
            } else if(equation[i]=='x') {
                ///计算以x开头的
                xnum++;
                ++i;
            } else if(equation[i]=='+') {
                ++i;
                ///假设是以x开头
                if(equation[i]=='x') {
                    xnum++;
                    ++i;
                } else if(equation[i]>='0' && equation[i]<='9') {
                    int val=0;
                    while(i<equation.size() && equation[i]>='0' && equation[i]<='9' ) {
                        val*=10;
                        val+=equation[i]-'0';
                        i++;
                    }
                    ///假设以x结尾
                    if(i<equation.size() &&equation[i]=='x') {
                        xnum+=val;
                        i++;
                    } else {
                        ///以数字结尾
                        sum+=val;
                    }
                }
            } else if(equation[i]=='-') {
                ++i;
                ///假设是以x开头
                if(equation[i]=='x') {
                    xnum--;
                    ++i;
                } else if(equation[i]>='0' && equation[i]<='9') {
                    int val=0;
                    while(i<equation.size() && equation[i]>='0' && equation[i]<='9' ) {
                        val*=10;
                        val+=equation[i]-'0';
                        i++;
                    }
                    ///假设以x结尾
                    if(i<equation.size() &&equation[i]=='x') {
                        xnum-=val;
                        i++;
                    } else {
                        ///以数字结尾
                        sum-=val;
                    }
                }
            } else {
                ///以数字开头的
                if(equation[i]>='0' && equation[i]<='9') {
                    int val=0;
                    while(i<equation.size() && equation[i]>='0' && equation[i]<='9' ) {
                        val*=10;
                        val+=equation[i]-'0';
                        i++;
                    }
                    ///假设以x结尾
                    ///注意判断是否结尾了
                    if(i<equation.size() && equation[i]=='x') {
                        xnum+=val;
                        i++;
                    } else {
                        ///以数字结尾
                        sum+=val;
                    }
                }
            }
        }
        return 0;
    }

    string solveEquation(string equation) {
        int bx=0,ax=0,bsum=0,asum=0;
        int eqpos=0;
        int pos=mysearch(equation,bx,bsum,0);
        mysearch(equation,ax,asum,pos+1);

        ostringstream oss;
        string str;
        //cout<<bx<<"  "<<bsum<<"   "<<ax<<"  "<<asum<<endl;
        if(bx==ax) {
            if(asum!=bsum) {
                oss<<"No solution";
            } else {
                oss<<"Infinite solutions";
            }
        } else {
            oss<<"x="<<((asum-bsum)/(bx-ax));
        }
        return oss.str();
    }
};



int main() {
    //freopen("1.txt","r",stdin);
    string str;
    Solution s;
    while(cin>>str) {
        string res=s.solveEquation(str);
        //cout<<str<<endl;
        cout<<res<<endl;
    }
}
