/**
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，
输出两个数的乘积最小的。
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int start=0,last=array.size()-1;
        vector<int>res;
        while(start<last){
            int temp=array[start]+array[last];
            if(temp==sum){
				//相距越远,乘积越小
                res.push_back(array[start]);
                res.push_back(array[last]);
                break;
            }else if(temp<sum){
                start++;
            }else{
                last--;
            }
        }
        return res;
    }
};