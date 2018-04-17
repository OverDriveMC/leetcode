/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        return match(str,0,strlen(str),pattern,0,strlen(pattern) );
    }
    bool match(char*str, int ss, int sl, char * pattern,int ps, int pl){
        //ss可以等于sl,因为pattern后面可以通过*把后面所有的串都删掉
        //又str[sl]=='\0'所以不会出现匹配的情况
        if(ps>=pl ){
            return ss==sl;
        }
        ///每次判断下一位是否为*
        if(pattern[ps+1]=='*'){
            int spos=ss;
            ///假设str[ss]这个字母出现了很多次,这个循环遍历 * 可能的所有次数
            //每次spos往后增加,ps不做变化
            while((spos<=sl) && ( str[spos]==pattern[ps] || pattern[ps]=='.' ) ){
                if(match(str, spos+1, sl, pattern, ps,pl )){
                    return true;
                }
                spos++;
            }
            ///假如跳出循环,说明无论*为>=1次时,都不能成功匹配,所以直接跳过该字母,*为0次
            return match(str, ss, sl, pattern, ps+2, pl);
        }else{
            if( (ss<sl)&& ( str[ss]==pattern[ps] || pattern[ps]=='.') ){
                return match(str,ss+1,sl, pattern,ps+1,pl);
            }else{
                return false;
            }
        }
    }
};