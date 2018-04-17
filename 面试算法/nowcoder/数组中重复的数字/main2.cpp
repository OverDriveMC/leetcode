class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length<=0){
            return false;
        }        
        for(int i=0;i<length;i++){
            if(numbers[i]<0 || numbers[i]>(length-1)){
                return false;
            }
        }
        for(int i=0;i<length;i++){
			/*
			因为是0-n-1
			每次将数交换到相应的下标
			如果发现对应下标的数已经等于下标了,说明重复了
			*/
            while(numbers[i]!=i){
                if( numbers[ numbers[i] ] ==numbers[i]  ){
                    *duplication=numbers[i];
                    return true;
                }
                swap(numbers[i],numbers[ numbers[i] ]  );
            }
        }
        return false;
    }
};