/**
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()==0){
            return ;
        }
        int res=data[0];
        for(int i=1;i<data.size();i++){
            res ^=data[i];
        }
		//找到第一个1的位置
        res &=-res;
		/**
		* 因为任何数与0异或都是0,所以不用标记位了
		*/
        for(int i=0;i<data.size();i++){
			//分为两类去异或
            if(data[i]&res){
                *num1 ^=data[i];
            }else{
                *num2 ^=data[i];
            }
        }
    }
};