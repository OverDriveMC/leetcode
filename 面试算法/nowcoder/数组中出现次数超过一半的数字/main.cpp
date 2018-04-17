/**
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int times=0,x;
        int index=0;
        while(index<numbers.size()){
			//假如次数为0,更新为新的数
            if(times==0){
                times++;
                x=numbers[index];
            }else if(x==numbers[index]){
				//相同次数+1,否则减1
                times++;
            }else{
                times--;
            }
            index++;
        }
		/**
		最后需要特别判断一下是否真的超过一半
		1 2 1 2
		*/
        int cnt=0;
        int half=numbers.size()/2;
        for(int i=0;i<numbers.size();i++){
           if(numbers[i]==x){
               cnt++;
           }
        }
        return cnt>half ? x : 0;
    }
};