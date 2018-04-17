class Solution {
public:
/**
*一定要注意传递引用
*/
    int partition(vector<int>&input, int begin, int end){
        int pivot=input[begin];
        int pos=begin;
        for(int i=begin+1;i<=end;i++){
            if(input[i]<pivot){
                swap(input[i],input[++pos]);
            }
        }
        swap(input[begin],input[pos]);
        return pos;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k==0 || input.size()<k){
            return vector<int>();
        }
        random_shuffle(input.begin(),input.end());
        
        int start=0,last=input.size()-1;
		///直到index==k-1的时候结束
        int index=partition(input,start,last);
        while(index!=k-1){
			///只需要找到[0,k-1]的数即可
            if(index>=k){
                last=index-1;
                index=partition(input,start,last);
            }else{
                start=index+1;
                index=partition(input,start,last);
            }
        }
        vector<int>res(input.begin(),input.begin()+k);
        return res;
    }
};