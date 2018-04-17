#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k==0 || input.size()<k){
            return vector<int>();
        }
        vector<int>res(input.begin(),input.begin()+k);
        make_heap(res);
        for(int i=k;i<input.size();i++){
            //cout<<res[0]<<"  "<<res[1]<<endl;
            if(input[i]<res[0]){
                res[0]=input[i];
                adjustHeap(res,res.size(),0);
            }
        }

        for(int i=res.size()-1;i>0;i--){
            swap(res[0],res[i]);
            adjustHeap(res,i+1,i);
        }

        return res;

    }
	/**
	* 一定要注意传递引用
	*/
    void make_heap(vector<int>&vec){
         for(int i=vec.size()/2-1; i>=0;i--){
             adjustHeap(vec,vec.size(),i);
         }
    }
    void adjustHeap(vector<int>&vec,int size,int pos){
        while(pos<size){
            int toPos=pos;
            int left=pos*2+1;
            if(left<vec.size() &&vec[left]>vec[pos]){
                toPos=left;
            }
            int right=left+1;
            if(right<vec.size() &&vec[toPos]<vec[right]){
                toPos=right;
            }
            if(toPos!=pos){
                swap(vec[pos],vec[toPos]);
                pos=toPos;
            }else{
                break;
            }
        }
    }
};

int main(){
    Solution s;
    int t[]={4,5,1,6,2,7,2,8};
    vector<int> input(t,t+8);
    s.GetLeastNumbers_Solution(input,2);

}
