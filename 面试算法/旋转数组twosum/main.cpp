#include<bits/stdc++.h>

using namespace std;

bool pairInRotateArray(int*arr,int len,int sum){
	bool flag=false;
	int l=0,r=len-1;
	for(int i=1;i<len;i++){
		if(arr[i]<arr[i-1]){
			l=i;
			r=i-1;
			break;
		}
	}
	while(l<r){
		if(arr[l]+arr[r] ==sum ){
			return true;
		}else if(arr[l]+arr[r]<sum){
			l=(l+1)%len;
		}else{
			r=
		}
	}
	return flag;
}


int main(){
	
	
	return 0;
}