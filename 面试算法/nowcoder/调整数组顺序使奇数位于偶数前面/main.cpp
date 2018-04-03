/**
1 2 3 4 5 6 7
第一次交换过后: 1 3 2 5 4 7 6
第二次交换过后: 1 3 5 2 7 4 6
第三次交换过后: 1 3 5 7 2 4 6
*/


class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i=0;i<array.size();i++){
            for(int j=array.size()-1;j>i;j--){
                //&作与运算的时候优先级没有 ==高
				/**
				* 每次后面是奇数前面是偶数的情况下交换位置
				*/
                if( (array[j]&1)  && ((array[j-1]&1)==0) ){
                    swap(array[j],array[j-1]);
                }
            }
        }
    }
};