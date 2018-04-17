class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(len<=0 || k>len){
            return vector<int>();
        }
        //红黑树:multiset集合,利用仿函数改变顺序,时间复杂度O(nlogk)
        multiset<int, greater<int>>leastNums;
        for(int i=0;i<input.size();i++){
            if(leastNums.size()<k){
                leastNums.insert(input[i]);
            }else{
                //第一个元素是最大值
                if(input[i] < *(leastNums.begin())){
                    leastNums.erase(leastNums.begin());
                    leastNums.insert(input[i]);
                }
            }
        }
        return vector<int>(leastNums.begin(),leastNums.end());
    }
};