/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string==NULL){
            return false;
        }
        
        char *str=string;
        int len=strlen(string);
        int pcnt=0;
        for(int i=0;i<len;i++){
            if(str[i]>'9' || str[i]<'0' ){
                if(str[i]=='+' || str[i]=='-'){
                    if(i!=0){
                        return false;
                    }
                }else if(str[i]=='e' || str[i]=='E'){
                    int j=i+1;
                    while(j<len){
                        if(str[j]>'9' || str[j]<'0'){
                            if(str[j]=='+' || str[j]=='-'){
                                //再出现 + -必须在i+1的位置
								//12e
                                if(j!=(i+1) ){
                                    return false;
                                }
                            }else{
                                return false;
                            }   
                        }
                        j++;
                    }
                    //防止e后面没有数字
                    return j!=(i+1);
                }else if(str[i]=='.'){
                    if(pcnt!=0){
                        return false;
                    }
                    pcnt++;
                }else{
                    return false;
                }
                
            }
        }
        return true;
    }

};