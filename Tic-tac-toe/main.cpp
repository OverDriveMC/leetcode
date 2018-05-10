/**
http://codeforces.com/contest/3/problem/C
3*3的棋盘下井字棋
一个人画 X,一个人画0
当一个人有竖直、水平或者对角线形成3个一样的图形即获胜
画X的人先下, 假如棋盘满了,X和0都没有形成3个,那么是平局(draw)
给定当前棋局情况,判断当前状态
first:轮到第一个人下棋
second:轮到第二个人下棋
illegal:非法状态
the first player won:第一个人获胜
the second player won or draw.:第二个人获胜
X0X
.0.
.X.
second
*/

#include<bits/stdc++.h>

using namespace std;

char str[3][4];

int dirs[4][2]={{1,0},{0,1},{1,1},{1,-1} };
/**
以当前位置为开始位置,分别往四个方向搜索, 右,下，右下,左下
不需要往回搜,只要往没有搜索过的位置搜索即可
*/
bool search(int x, int y, char charac){
	for(int i=0;i<4;i++){
		int cnt=1;
		for(int j=1;j<=2;j++){
			int dx=x+dirs[i][0]*j;
			int dy=y+dirs[i][1]*j;
			if(dx>=0 && dx<3 && dy>=0 && dy<3 && str[dx][dy]==charac){
				cnt++;
			}else{
				break;
			}
		}
		if(cnt==3){
			return true;
		}
	}
	return false;
}

int main(){
    //freopen("1.txt","r",stdin);
	for(int i=0;i<3;i++){
		scanf("%s",str[i]);
	}
	int cntcross=0, cntnoughts=0;
	bool crossflag=false, noughtsflag=false;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(str[i][j]=='X'){
				cntcross++;
				if(!crossflag && search(i,j,'X')){
					crossflag=true;
				}
			}else if(str[i][j]=='0'){
				cntnoughts++;
				if(!noughtsflag && search(i,j,'0')){
					noughtsflag=true;
				}
			}
		}
	}
	//cout<<crossflag<<"  "<<noughtsflag<<"   "<<cntcross<<"   "<<cntnoughts<<endl;
	/**
	非法状态一共有4种情况:
	1.X的数量小于0
	2.X的数量 - 0的数量 >1
	3.X的数量等于0的数量,而此时存在3个X相连(先手获胜),不可能出现,因为先手下子之后,X的数量必然多于0的数量
	4.X的数量大于0的数量,而此时存在3个0相连(后手获胜),不可能出现,因为后手下子之后赢了,必然X的数量与0的数量相等
	*/
	if(cntnoughts>cntcross || (cntcross-cntnoughts>1) || (crossflag && cntnoughts==cntcross) || (noughtsflag && (cntcross>cntnoughts)) ){
		printf("illegal\n");
	}else if(crossflag){
		printf("the first player won");
	}else if(noughtsflag){
		printf("the second player won\n");
	}else if( cntcross==cntnoughts ){
		printf("first\n");
	}else if( (cntcross-cntnoughts)==1 && (cntcross!=5) ){
		printf("second\n");
	}else{
		printf("draw\n");
	}
	return 0;
}