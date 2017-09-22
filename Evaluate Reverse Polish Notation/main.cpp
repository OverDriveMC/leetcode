#include<bits/stdc++.h>

using namespace std;
/**
*注意考虑负数
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<int>num;
		for(int i=0;i<tokens.size();i++){
			if(tokens[i].size()!=1
                    || (tokens[i][0]>='0' && tokens[i][0]<='9' )   ){
				int temp=0;
				int startpos=0;
				//注意判断负数
				if(tokens[i][0]=='-'){
                    startpos=1;
				}
				for(int j=startpos;j<tokens[i].size();j++){
					temp=temp*10+(tokens[i][j]-'0' );
				}
				num.push(startpos==1 ? -temp : temp);
			}else if(tokens[i][0]=='+'){
				int val1=num.top();
				num.pop();
				int val2=num.top();
				num.pop();
				num.push(val1+val2);
			}else if(tokens[i][0]=='-'){
				int val1=num.top();
				num.pop();
				int val2=num.top();
				num.pop();
				num.push(val2-val1);
			}else if(tokens[i][0]=='*'){
				int val1=num.top();
				num.pop();
				int val2=num.top();
				num.pop();
				num.push(val2 * val1);
			}else if(tokens[i][0]=='/'){
				int val1=num.top();
				num.pop();
				int val2=num.top();
				num.pop();
				num.push(val2/val1);
			}


		}
		return num.top();
    }
};


int main(){
	Solution s;
/*
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
	vector<string>tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
	cout<<s.evalRPN(tokens)<<endl;
	tokens.clear();
	tokens.push_back("4");
	tokens.push_back("13");
	tokens.push_back("5");
	tokens.push_back("/");
	tokens.push_back("+");
	cout<<s.evalRPN(tokens)<<endl;
    tokens.clear();
	tokens.push_back("3");
	tokens.push_back("-4");
	tokens.push_back("+");
	cout<<s.evalRPN(tokens)<<endl;
}
