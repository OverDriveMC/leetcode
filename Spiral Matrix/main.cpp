#include<bits/stdc++.h>

using namespace std;
/**
每次特判cnt< m*n 防止重复添加
例如：
2 3

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.size()==0) {
            return res;
        }
        int cnt=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int round=0;
        int x,y;
		while(cnt< m*n){
			x=round,y=round;
			while(cnt<m*n && y<n-round ){
				res.push_back(matrix[x][y++]);
				cnt++;
			}
			if(y==n-round){
				y--;
			}
			x++;

			while(cnt<m*n &&x<m-round){
				res.push_back(matrix[x++][y]);
				cnt++;
			}
			if(x==m-round){
				x--;
			}
			y--;
			while(cnt<m*n &&y>=round){
				res.push_back(matrix[x][y--]);
				cnt++;
			}
			if(y==round-1){
				y++;
			}
			x--;
			while(cnt<m*n &&x>round){
				res.push_back(matrix[x--][y]);
				cnt++;
			}
			round++;

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
