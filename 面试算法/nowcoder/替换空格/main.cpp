/*
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==NULL || length<0){
            return ;
        }
        int cnt=0;
        for(int i=0;i<length;i++){
            if(str[i]==' '){
                cnt++;
            }
        }
		//替换后的长度为length+ cnt*2  注意是 *2
        int pos1=length+cnt*2;
		//一定要记得补\0
        str[pos1]='\0';
        int pos2=length-1;
        while(pos1--){
            if(str[pos2]==' '){
                str[pos1--]='0';
                str[pos1--]='2';
                str[pos1]='%';
            }else{
                str[pos1]=str[pos2];
            }
            pos2--;
        }
	}
};