/**
车无限gas tank
花费cost[i]从i到i+1
N Gas Station是环形,gas数量为gas[i]
判断从哪点出发可以绕环一周,否则返回-1
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==0){
            return 0;
        }
        vector<int>dif(gas.size(),0);
        int val=0;
        for(int i=0;i<gas.size();i++){
			///计算差值,同时统计差值
            dif[i]=gas[i]-cost[i];
            val+=dif[i];
        }
		///假如差值的和<0,说明任一点出发都不可能绕环1周
        if(val<0){
            return -1;
        }
        int maxIndex=-1;
		///记录当前剩余油量
        int cur=0;
        for(int i=0;i<gas.size();i++){
            cur+=dif[i];
			///当油量大于等于0,并且maxIndex还是-1的位置,更新maxIndex起始位置
			///一旦cur>=0,便统计第一个大于等于0的位置,因为如果之后不会出现<0那么这个位置便可以作为起始位置
			///下标从0 开始
            if(cur>=0 && maxIndex==-1){
                maxIndex=i;
            }else if(cur<0){
				//一旦小于0，说明cur这个位置到这个位置i都不行
                cur=0;
                maxIndex=-1;
            }
        }
        return maxIndex;
    }
};