#include<bits/stdc++.h>
using namespace std;
/**
*剪枝回溯
*每次只回溯到最近的*
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int presp,press;
        bool flag=false;
        int i=0,j=0;
        while(i<s.length()){
			///不需要判断j是否超出长度
			///假如判断的话可能j有一个*匹配了s的所有串、
			///不会出现越界，匹配不了的时候会自动退出
			
            ///cout<<"i:"<<i<<endl;
			///使用presp记录 当前遍历过的p串的最近的一个*
			///回溯的时候不需要回溯到之前的*了
			///同时使用press记录s中这个*匹配的结束位置
            if(p[j]=='*'){
                presp=++j;
                press=i;
                flag=true;
            }else if(p[j]=='?' || (s[i]==p[j]) ){
                i++;
                j++;
            }else if(flag){
				///只要flag为真，就说明肯定前面有*
				///失配时j自动再从*的下一个为止匹配
				///*从匹配0个到匹配s.length()一直尝试，或者是
				///碰到下一个*时更换press位置。否则press每次往后+1
				///代表*匹配的结束位置一直加1
                j=presp;
                i=++press;
            }else{
                return false;
            }
        }
        while(j< p.length()){
            if(p[j]=='*'){
                j++;
            }else{
                return false;
            }
        }

        return j==p.length();
    }
};

int main(){
    Solution s;
    cout<<s.isMatch("a","a*")<<endl;
    cout<<s.isMatch("","*")<<endl;
    cout<<s.isMatch("aa","a")<<endl;
    cout<<s.isMatch("aa","aa")<<endl;
    cout<<s.isMatch("aaa","aa")<<endl;
    cout<<s.isMatch("aa", "*")<<endl;
    cout<<s.isMatch("aa", "a*")<<endl;
    cout<<s.isMatch("ab", "?*")<<endl;
    cout<<s.isMatch("aab", "c*a*b")<<endl;
    return 0;
}
