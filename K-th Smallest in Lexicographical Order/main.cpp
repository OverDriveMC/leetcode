#include<bits/stdc++.h>
using namespace std;


typedef long long LL;
class Solution {
public:
    int findKthNumber(int n, int k) {
		int ans=1;
		k=k-1;
/**
* 现在的k代表第k大,从0开始
* 假如为0,结果便是ans
*/
		while(k>0){
/**
* findGap:查找[ans,ans+1]之间有多少个数
* 假如gap<=k 说明 第k大不在当前的区间内,
* 因为这个范围为从ans开始的第[0,gap-1]大
*/
			int gap=findGap(n,ans,ans+1);
			if(gap<=k){
				ans++;
				k=k-gap;
			}else{
/**
* 假如gap>k 说明第k大在这根树里面
* k==0,则是根节点,假如不是0,说明在子树里面
* 跳到子树里面继续查找
*/
				ans=ans*10;
				k--;
			}
		}

		return ans;
    }
    /**
    * 这里要用long long,否则这里会出现越界的情况
    */
	int findGap(LL n,LL start,LL last){
		int gap=0;
		while(start<=n){
			gap+=min(last,n+1)-start;
			start*=10;
			last*=10;
			///最后一次 *10 的时候可能溢出
            //cout<<start<<"  "<<last<<endl;
		}
		return gap;
	}
};


int main(){
    Solution s;
    cout<<"res:"<<s.findKthNumber(13,5)<<endl;
    cout<<"res:"<<s.findKthNumber(13,6)<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"res:"<<s.findKthNumber(681692778,351251360)<<endl;
}
