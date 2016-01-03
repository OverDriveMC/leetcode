#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    P   A   H   N
    A P L S I I G
    Y   I   R
    */
    string convert(string s, int numRows) {
        ///因为这个方法要去掉首尾两行，所以必须保证行数大于2
        if(numRows==1){
            return s;
        }

        string lines[numRows];
        int cnt=0;
        while(cnt<s.length()){
            ///正着往下遍历，每次把当前行的元素添加至维护当前行
            ///的string数组lines中，同时注意防止不够一行了，所以
            ///需要判断是否到了末尾
            for(int row=0;row<numRows && cnt<s.length();row++){
                lines[row]+=s[cnt++];
            }
            ///倒着再往回加，去掉第一行和最后一行的元素
            for(int row=numRows-2;row>0 && cnt<s.length() ;--row){
                lines[row]+=s[cnt++];
            }
        }
        string res;
        ///最后将每一行的元素拼接起来，即为最后的字符串
        for(int row=0;row<numRows;row++){
            //cout<<lines[row]<<endl;
            res+=lines[row];
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.convert("ABCDEFG",1)<<endl;
    cout<<s.convert("PAYPALISHIRING", 3) <<endl;
    return 0;
}
