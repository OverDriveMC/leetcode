/**
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
*/

class Solution {
public:
    string ReverseSentence(string str) {
        int begin=0;
        for(int i=0;i<str.size();i++){
			///每段单词先翻转
            if(str[i]==' '){
                swap(str,begin,i-1);
                begin=i+1;
            }
        }
		//记得最后一段的翻转
        swap(str,begin,str.size()-1);
		//然后整体翻转
        swap(str,0,str.size()-1);
        return str;
    }
    void swap(string&str, int start,int last){
        while(start<last){
            str[start]^=str[last]^=str[start]^=str[last];
            start++;
            last--;
        }
    }
};