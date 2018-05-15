/**
给定一个字符串,找出字符串中所有前缀长度为i的可以写成 A^k的形式
输入：长度  字符串
输出: 前缀长度i, 可以复制几次k
input:
3  aaa
output:
Test case #1
2 2    aa   a^2
3 3    aaa  a^3

input:
12 aabaabaabaab
output:
Test case #2:
2 2   aa  a^2
6 2   aabaab  aab^2
9 3   aabaabaab   aab^3
12 4  aabaabaabaab  aab^4
*/

#include<cstdio>
#include<vector>

using namespace std;

const int maxn=1e6+5;
char str[maxn];
int len;
vector<int>getNext(){
	vector<int>next(len,0);
	int pos=0,index=1;
	while(index<len){
		while(pos>0 && str[pos]!=str[index]){
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
    //freopen("1.txt","r",stdin);
	int cnt=1;
	while(true){
		scanf("%d",&len);
		if(len==0){
			break;
		}
		scanf("%s",str);
		vector<int>next=getNext();
		printf("Test case #%d\n",cnt++);
		for(int i=1;i<=len;i++){
            ///next[i-1]>0防止 (i/(i-next[i-1]) ==1)
			if((next[i-1]>0) &&( i % (i- next[i-1]) ==0 )   ){
                printf("%d %d\n",i, i/ (i-next[i-1])  );
			}
		}
		printf("\n");
	}
	return 0;
}
