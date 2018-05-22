/**
http://acm.hdu.edu.cn/showproblem.php?pid=4864
一共有N个机器,M 个任务
每个任务有两个值花费时间x和难度y
每个机器也有两个值最大工作时间x1,和最大工作难度y
机器可以胜任某个工作的条件是x1>=x && y1>=y ,机器胜任一个工作可以拿到 x*500+2*y的钱, 
计算怎么样匹配才能完成最多的任务,任务个数相同的情况下,选择钱最多的那种。

因为
money = 500 *x  + 2 * y
时间差1,那么会相差500,而y的范围是[0-100],所以y之间的差最多为200
所以可以采用贪心的办法,先选择时间最高的完成,
当时间都相同的时候,选择难度更大的去完成。

一开始先将工作按照x降序排列,x相同的时候按照y降序排列。
这样如果前面的工作能完成一定先选择前面的工作去完成,这样才能保证获取更多的钱。

之后再遍历任务的时候,可能会出现多个机器都可以完成该任务,在这些机器中选择最小的y1来完成。
这样就可以保留比较大的y1去匹配后面的任务(后面的任务可能有时间用的少,但是难度可能很大),而x1则完全不用操心,
肯定可以匹配后面的任务,因为任务是按照x降序排列的。

例如：
机器：
machine1:100    100
machine2:99    5

任务:
Task1: 98     1
Task2: 80     99

这个时候对于Task1, machine1,machine2都可以满足要求,那么选择难度小的machine去完成即可,留着machine1去完成难度大的task

所以通过引入一个新的数组cnt,在cnt里记录难度为 i的 机器有多少个处于空闲状态,因为时间上能够满足之前的task，对于后面的task必然也能够满足

*/


#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn=1e5+5;

struct Node{
	int x,y;
	bool operator<(const Node& node) const{
		if(x!=node.x ){
			return x>node.x;
		}else{
			return y>node.y;
		}
	}
};

Node machine[maxn],task[maxn];
int cnt[105];
int N,M;

int main(){
	while(scanf("%d%d",&N,&M)!=EOF ){
		for(int i=0;i<N;i++){
			scanf("%d%d",&machine[i].x, &machine[i].y);
		}
		for(int i=0;i<M;i++){
			scanf("%d%d",&task[i].x, &task[i].y);
		}
		sort(machine,machine+N);
		sort(task, task+M);
		memset(cnt,0,sizeof(cnt));
		int num=0;
		LL money=0;
		int j=0;
		for(int i=0;i<M;i++){
            while(j<N && task[i].x <=machine[j].x){
				/**
				记录下所有时间上能够满足该任务的 难度
				cnt[ hard ]：表示能完成难度hard的机器有多少个空闲  (因为task时间有序,所以可以保证时间上一定满足)
				*/
                cnt[machine[j].y ]++;
                j++;
            }
			/**
			从当前工作的难度开始遍历,最高难度为100,选择一个难度最低的machine去完成即可。
			*/
            for(int k=task[i].y;k<=100;k++){
                if(cnt[k]>0){
                    cnt[k]--;
                    num++;
                    money+=task[i].x*500 + 2*task[i].y;
                    break;
                }
            }
		}



		printf("%d %lld\n",num,money);
	}
	return 0;
}
