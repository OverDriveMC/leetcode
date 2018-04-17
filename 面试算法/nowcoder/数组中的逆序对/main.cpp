/**
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod=1e9+7;
    int InversePairs(vector<int> data) {
        int res=getInverse(data,0,data.size()-1);
        return res;
    }
    int getInverse(vector<int>&data,int start,int last){
        if(last<=start){
            return 0;
        }
        int mid=start+(last-start)/2;
        int left=getInverse(data,start,mid);
        int right=getInverse(data,mid+1,last);
        int res=(left+right)%mod;
        int i=start,j=mid+1;
		//注意,如果这里初始化了大小,那么push_back会从初始化的大小的后一个位置开始添加元素
        vector<int>tmp;
        while(i<=mid || j<=last){
            if(i>mid || (j<=last &&  data[i]>data[j] ) ){
                tmp.push_back(data[j++]);
				///每次后面添加一个元素,说明前面有(mid-i+1)个元素比它大
                res=(res+(mid-i+1) ) %mod;
            }else{
                tmp.push_back(data[i++]);
            }
        }
        for(int i=start;i<=last;i++){
            data[i]=tmp[i-start];
        }
        return res;
    }
};

int main(){
    Solution s;

    int a[]={1,2,3,4,5,6,7,0};
    vector<int>vec(a,a+8);
    cout<<s.InversePairs(vec)<<endl;

}
