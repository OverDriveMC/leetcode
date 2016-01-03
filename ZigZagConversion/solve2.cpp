#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
    *所有行的重复周期都是 2 * nRows - 2
    *对于首行和末行之间的行，还会额外重复一次，
    *重复的这一次距离本周期起始字符的距离是 2 * nRows - 2 - 2 * i
    *也就是中间的斜线单算
    */
    /*
    P   A   H   N
    A P L S I I G
    Y   I   R
    */
    string convert(string s, int numRows) {
        string str;
        if(numRows==1){
            return s;
        }
        for(int i=0;i<numRows;i++){
            int pos=i;
            while(pos<s.length()){
                str+=s[pos];
                if(i!=0 && i!= numRows-1){
                    int nextpos=pos+(numRows-i)*2-2;
                   // cout<<i<<"   "<<nextpos<<endl;
                    if(nextpos<s.length()){
                        str+=s[nextpos];
                    }
                }
                pos+=(2*numRows-2);
            }
        }
        return str;
    }
};



int main(){
    Solution s;
    cout<<s.convert("ABC",3)<<endl;
    cout<<s.convert("ABCDEFG",1)<<endl;
    cout<<s.convert("PAYPALISHIRING", 3) <<endl;
    cout<<s.convert("PAYPALISHIRING",4) <<endl;
    return 0;
}
