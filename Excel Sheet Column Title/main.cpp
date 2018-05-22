/**
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
将数字转换成字母

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n){
			/**
			1-26   ======> A- Z
			0-25  +1 ======>A-Z
			
			例如当前是26, 正常是    (26-1)%26 +'A'
			*/
            res.push_back('A' + (n-1)%26);
            n=(n-1)/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution2 {
public:
    string convertToTitle(int n) {
        return n==0 ? "" : convertToTitle(n/26 ) +(char)('A' + (--n)%26);
    }
};

int main(){
    Solution2 s;
    cout<<s.convertToTitle(1)<<endl;
    cout<<s.convertToTitle(26)<<endl;
    cout<<s.convertToTitle(27)<<endl;
    cout<<s.convertToTitle(53)<<endl;
    cout<<s.convertToTitle(703)<<endl;
    return 0;
}
