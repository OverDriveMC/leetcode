#include<bits/stdc++.h>

using namespace std;
const int M=5;
const int N=1;
const int maxn=M*N;

int getNext(int pos){
	int row=pos/N;
	int column=pos%N;
	return column*M+row;
}
void moveData(vector<int>&vec,int start){
	int next=getNext(start);
	while(next!=start){
        ///每次数据都是与开始位置的数据交换,直到最后一组数据就是移动到开始位置
		swap(vec[start],vec[next]);
		next=getNext(next);
	}
}

void transpose(vector<int>&vec){
	for(int i=0;i<maxn;i++){
		int next=getNext(i);
		///假如后继不存在比i小的元素
		while(next>i){
			next=getNext(next);
		}
		///最后next会移到i,这时可以移动数据
		if(next==i){
			moveData(vec,i);
		}
	}
}


int main(){
	vector<int>vec;
	for(int i=0;i<maxn;i++){
		vec.push_back(i+1);
	}
	cout<<"before transpose:"<<endl;
	for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<vec[i*N+j]<<"  ";
        }
        cout<<endl;
	}
	transpose(vec);
	cout<<"after transpose"<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<vec[i*M+j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}
