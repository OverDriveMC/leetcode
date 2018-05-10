/**
给定字符串s,通过在开头添加最短的字符,使它变成回文串
Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"

计算以第一个字符开头的最长回文串,回文串越长,那么需要补充的字母越少
所以先将原串翻转,然后查找以第一个字符开头的最长回文串
例如: abcbabcab
      bacbabcba
abcba是最长回文串,剩下的串为bcab,
所以需要补充 bacb
最终结果为:  bacbabcbabcab
时间复杂度O(n^2)  空间复杂度O(n)
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string revs(s);
        reverse(revs.begin(),revs.end());
		//遍历长度
        for(int i=s.size();i>=0;i--){
            if(s.substr(0,i) ==revs.substr(s.size()-i ,i)  ){
                return revs.substr(0, s.size()-i) +s;
            }
        }
    }
};