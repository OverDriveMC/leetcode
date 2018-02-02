#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.size()==0 || matrix[0].size()==0){
			return ;
		}
		int rows=matrix.size();
		int cols=matrix[0].size();
		int col0=1;
		/**
		如果matrix[i][j]==0的话,那么便把matrix[i][0]和matrix[0][j]置为0,通过每行每列的第一个元素来标记该行该列是否全部应该置为0
		但是这样会有一个问题：
		1 0 1
		0 1 1
		1 1 1
		因为matrix[0][1]为0,所以需要把matrix[0][0]置为0,但是matrix[0][0]置为0后,会把第0列全部置为0,所以可以通过每行第一个元素和每列第一个元素标记
		但是不能影响第一行和第一列的元素标记。
		所以通过一个col0来标记第一列的元素是否应该置为0,只要matrix[i][0]中有一个为0,那么col0就应该置为0,这样所有的第一列元素应该都为0
		对于第一行的元素,需要最后做标记,标记完其它行之后,可以根据matrix[0][0]的值来判断是否需要标记,有的也会因为列内有0元素,已经被标记为0
		不能先标记第一行,会影响其他行的标记(因为如果原本matrix[0][0]不为0,但是因为后面的元素标记matrix[0][0]==0,那么第一行所有元素都会被标记为0)
		*/
		for(int i=0;i<rows;i++){
			if(matrix[i][0]==0) col0=0;
			/**
			这里需要从j=1开始
			例如
			1 1 1
			0 1 2
			假如从0开始的话,会因为matrix[1][0]==0,把matrix[0][0]标记为0,这样在标记第一行的时候会把所有的第一行元素都标记为0
			如果从1开始的话,因为matrix[1][0]==0,会把col0标记为0,这样标记第一行元素的时候,因为标记顺序是1-cols,最后才标记matrix[0][0],
			所以能够保证后面的元素都被正确标记完,最后根据col0==0将matrix[0][0]置为0
			*/
			for(int j=1;j<cols;j++){
				if(matrix[i][j]==0){
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
			}
		}
		for(int i=rows-1;i>=0;i--){
			for(int j=1;j<cols;j++){
				if(matrix[i][0]==0 || matrix[0][j]==0){
					matrix[i][j]=0;
				}
			}
			if(col0==0){
				matrix[i][0]=0;
			}
		}

    }
};

int main(){
	vector<vector<int> >vec;
	vector<int>vec1;
	vec1.push_back(0);
	vec1.push_back(0);
	vec1.push_back(0);
	vec1.push_back(5);
	vec.push_back(vec1);

	vector<int>vec2;
	vec2.push_back(4);
	vec2.push_back(3);
	vec2.push_back(1);
	vec2.push_back(4);
	vec.push_back(vec2);

	vector<int>vec3;
	vec3.push_back(0);
	vec3.push_back(1);
	vec3.push_back(1);
	vec3.push_back(4);
	vec.push_back(vec3);

	vector<int>vec4;
	vec4.push_back(1);
	vec4.push_back(2);
	vec4.push_back(1);
	vec4.push_back(3);
	vec.push_back(vec4);

	vector<int>vec5;
	vec5.push_back(0);
	vec5.push_back(0);
	vec5.push_back(1);
	vec5.push_back(1);
	vec.push_back(vec5);

	Solution s;
	s.setZeroes(vec);
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++){
			cout<<vec[i][j]<<"  ";
		}
		cout<<endl;
	}
}
