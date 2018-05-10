/**
a*b 定义为两个字符串 concat
如果a='abc'  b='def'
a*b='abcdef'
a^(n+1)= a*(a^n)

对于每个输入s,打印最大的n,使 s=a^n

abcd    1
aaaa    4
ababab  3
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn=1e7+5;

char str[maxn];
int len;
vector<int> getNext(char *str){
	vector<int>next(len,0);
	int pos=0,index=1;
	while(index < len){
		while(pos>0 && str[pos]!=str[index] ){
			pos=next[pos-1];
		}
		if(str[pos]==str[index]){
			pos++;
		}
		next[index]=pos;
		index++;
	}
	return next;
}

int main(){
	while(true){
		scanf("%s",str);
		if(!strcmp(str,".")){
			break;
		}
		len=strlen(str);
		vector<int>next=getNext(str);
		int relen=len-next[len-1];
		printf("%d\n",len/relen);
	}
	return 0;
}
