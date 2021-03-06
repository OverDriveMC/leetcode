#include<bits/stdc++.h>
/**
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/
using namespace std;
/**
后面的丑数是前面的丑数 * 2,3,5中的一个得来
所以每次记录 *2 *3 *5的丑数位置

*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0){
            return 0;
        }
        vector<int>res(index,1);
        int t[]={0,0,0};
        for(int i=1;i<index;i++){
            res[i]=min(res[t[0] ]*2 ,min(res[t[1]]*3, res[t[2]]*5 ));
			/**
			* 注意,每个都要写if,因为可能有重复元素
			* 例如6 ==2*3 == 3*2
			*/
            if(res[i]==res[t[0] ]*2 ) t[0]++;
            if(res[i]==res[t[1] ]*3) t[1]++;
            if(res[i]==res[t[2] ]*5) t[2]++;
        }
        return res[index-1];
    }
};

int main(){
    Solution s;
    s.GetUglyNumber_Solution(8);
    return 0;
}
