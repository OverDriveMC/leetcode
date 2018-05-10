/**
通过补充最少的串,成为循环串
3
aaa      0
abca   补充bc===>abcabc  2
abcde  补充abced=====>abcdeabcde  5

最小循环节 = 原串长度- 末位失配
首先判断循环节是否为0  =========>直接输出原串长度
看原串是否能被循环节整除 ========>能,输出0

*/

#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
char str[maxn];
int len;
int N;

vector<int> getNext(char*str){
	len=strlen(str);
	vector<int>next(len,0);
	int pos=0,index=1;
	while(index<len){
		while(pos>0 && str[index]!=str[pos] ){
			pos=next[pos-1];
		}
		if(str[index]==str[pos]){
			pos++;
		}
		next[index]=pos;
		index++;
		//cout<<"index:"<<index<<"   "<<next[index]<<endl;
	}
	return next;
}


int main(){
    //freopen("1.txt","r",stdin);
	scanf("%d",&N);
	while(N--){
		scanf("%s",str);
		vector<int>next=getNext(str);
		int relen= len- next[len-1];
		if( next[len-1] ==0){
            printf("%d\n",  len  );
		}else if(len%relen==0 ){
            printf("%d\n",  0 );
		}else{
            printf("%d\n",  relen-len%relen  );
		}
	}
	return 0;
}
