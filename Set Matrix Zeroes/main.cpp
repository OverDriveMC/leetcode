#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.size()==0 || matrix[0].size()==0){
			return ;
		}
		//只需要标记一下列
		int colvis[matrix[0].size()];
		memset(colvis,0,sizeof(colvis));

		for(int i=0;i<matrix.size();i++){
			///是否需要往前更新
			bool update=false;
			for(int j=0;j<matrix[i].size();j++){
				if(matrix[i][j]==0){
					if(colvis[j]==0){
						///需要往上更新
						colvis[j]=1;
						for(int k=0;k<i;k++){
							matrix[k][j]=0;
						}

					}
					if(!update){
						for(int k=0;k<j;k++){
							matrix[i][k]=0;
						}
						update=true;
					}
				}else {
					if(colvis[j]==1){
						matrix[i][j]=0;
					}
					if(update==true){
						matrix[i][j]=0;
					}
				}
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
