#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(int i=0;i<ops.size();i++){
            if(isdigit(ops[i][0]) || ops[i][0]=='-'){
                int temp=0;
                int startpos=0;
                if(ops[i][0]=='-'){
                    startpos=1;
                }
                for(int j=startpos;j<ops[i].size();j++){
                    temp=temp*10+(ops[i][j]-'0');
                }
                s.push(startpos==0?temp:-temp);
            }else if(ops[i][0]=='C'){
                s.pop();
            }else if(ops[i][0]=='D'){
                int temp=s.top();
                s.push(temp*2);
            }else if(ops[i][0]=='+'){
                int temp1=s.top();
                s.pop();
                int temp2=s.top();
                s.pop();
                s.push(temp2);
                s.push(temp1);
                s.push(temp1+temp2);
            }
        }
        int sum=0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};


int main()
{
    vector<string> ops;
    ops.push_back("5");
    ops.push_back("2");
    ops.push_back("C");
    ops.push_back("D");
    ops.push_back("+");
    Solution s;
    cout<<s.calPoints(ops)<<endl;
    return 0;
}
