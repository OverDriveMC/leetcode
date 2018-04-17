/**
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        set<int>set;
        for(int i=0;i<length;i++){
            if(set.find(numbers[i])==set.end() ){
                set.insert(numbers[i]);
            }else{
                *duplication=numbers[i];
                return true;
            }
        }
        return false;
    }
};

/**
//2,void erase(&pos) 移除pos位置上的元素，无返回值
//3,void erase(&first, &last) 移除迭代区间[&first, &last)内的元素，无返回值
*/