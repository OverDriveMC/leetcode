#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod=1e9+7;
    int InversePairs(vector<int> data) {
        vector<int>copy(data.begin(),data.end());
        int res=getInverse(data,copy,0,data.size()-1);
        return res;
    }
	//创建一个全局的,时间能快一半左右
    int getInverse(vector<int>&data,vector<int>&copy,int start,int last){
        if(last<=start){
            return 0;
        }
        int mid=start+(last-start)/2;
        int left=getInverse(data,copy,start,mid);
        int right=getInverse(data,copy,mid+1,last);
        int res=(left+right)%mod;
        int i=start,j=mid+1;
        int cnt=start;
        while(i<=mid || j<=last){
            if(i>mid || (j<=last &&  data[i]>data[j] ) ){
                copy[cnt++]=data[j++];
                res=(res+(mid-i+1) ) %mod;
            }else{
                copy[cnt++]=data[i++];
            }
        }
        for(int i=start;i<=last;i++){
            data[i]=copy[i];
        }
        return res;
    }
};

