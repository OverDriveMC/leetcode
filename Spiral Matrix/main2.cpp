#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.size()==0) {
            return res;
        }

        int m=matrix.size();
        int n=matrix[0].size();
        int round=0;
        int x=0,y=n-1;
		///这样便不需要重新添加第一行元素
        res=matrix[0];
		///剩下的需要添加的元素
		int cnt=(m-1)*n;
		///是个方向
		int dirs[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
		int d=0;
		while(cnt){
			/**
			* 因为每个方向走完都会判断一次是否还有元素需要添加
			*  所以不会出现重复添加元素的情况
			*/
			for(int i=1;i<m;i++){
				x+=dirs[d][0];
				y+=dirs[d][1];
				res.push_back(matrix[x][y] );
				cnt--;
			}
			///加完之后这个方向要添加的元素便要-1
			m--;
			///每次行列互换,横着走的时候使用n,纵走的时候使用m
			swap(m,n);
			d=(d+1)%4;
		}

        return res;
    }
};


void test1() {
    int n=4;
    vector<vector<int>> matrix;
    for(int i=1; i<=n*n;) {
        vector<int>vec;
        for(int j=1; j<=n; j++) {
            vec.push_back(i++);
        }
        matrix.push_back(vec);
    }
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    Solution s;
    vector<int>res=s.spiralOrder(matrix);

    cout<<endl<<endl;
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<"  ";
    }
    cout<<endl;

}

int main() {

    test1();
    vector<vector<int>> matrix;
    vector<int>vec;
    vec.push_back(2);
    vec.push_back(3);
    matrix.push_back(vec);
    Solution s;
    vector<int>res=s.spiralOrder(matrix);

    cout<<endl<<endl;
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<"  ";
    }
    cout<<endl;
    return 0;
}
