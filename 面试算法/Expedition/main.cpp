/**
http://poj.org/problem?id=2431
有N个加油站,每个加油站有加油的上限,从L点出发,要行进到0点,
每行进一个单位长度,就要花费一个单位油量,初始油量为p,
设在汽车存储油量没有上限的情况下,最少在多少个加油站加油
Input:
4
4 4
5 2
11 5
15 10
25 10
Output:2

0    4    5    11     15        25
汽车当前在25那个点,油量为10,
4个加油站分别在4 5 11 15
每个加油站可以加的油量为4 2 5 10
汽车先行进10个距离,在15那里加油10,然后在行进10，在5那里加油5,最后到达终点0
一共加了2次油
*/
/**
思路:贪心
卡车走的越远越好,要是不能到达终点,就选择经过的加油站里面,加油量最多的加油,然后继续。
所以先按照加油站距离终点的距离排序,
利用优先队列来存放经过的加油站,根据加油站加油的油量多少排序
*/
#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;

pair<int,int> node[10005];
priority_queue<int>pq;
int N;
int L,P;

int main(){
    //freopen("1.txt","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&node[i].first,&node[i].second);
	}
	scanf("%d%d",&L,&P);
	sort(node,node+N);

	int index=N-1;
	int cnt=0;
	//一开始先将剩余油量添加进去,就不用单独考虑了
	/**
	优先队列里面存储所有路过的加油站,并且油量多的优先级高
	*/
	pq.push(P);
	while(L>0 && !pq.empty()){
		///每次取油量最高的添加
		L-=pq.top();
		pq.pop();
		cnt++;
		/**
		将路过的加油站添加进队列里面
		index是个全局变量
		*/
		for(;index>=0;index--){
			if(node[index].first>=L){
				pq.push(node[index].second);
			}else{
                break;
			}
		}
	}
	//当L>0的时候,说明到达不了终点
	printf("%d\n", L<=0 ? cnt-1 : -1);
	return 0;
}
