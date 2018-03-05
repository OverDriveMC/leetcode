/**
	If car starts at A and can not reach B. Any station between A and B can not reach B.(B is the first 
				station that A can not reach.)
	If the total number of gas is bigger than the total number of cost. There must be a solution.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		//tank记录当前会多多少gas
		//total记录0-(start-1)位置缺了多少gas
        int start(0),tank(0),total(0);
        for(int i=0;i<gas.size();i++){
			///每次更新tank
			///假如多的gas<0说明不够
            if((tank=tank+gas[i]-cost[i])<0){
				///使用total记录缺的gas
                total+=tank;
				///tank归0
                tank=0;
				///start至少要是i+1位置,i之前的任何位置都不可能成功
                start=i+1;
            }
        }
		///最后判断total+tank即多的油量与缺的油量是否相加大于0
        return (total+tank <0) ? -1 : start;
    }
};