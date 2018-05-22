#include<bits/stdc++.h>

using namespace std;
/**
计算有多少个不同的小岛

可以通过旋转(90,180,270)或翻转(上下,左右)得到相同形状的小岛算一个
Example
Example 1:

11000
10000
00001
00011
Given the above grid map, return 1.

Notice that:

11
1
and

 1
11
are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.

Example 2:

11100
10001
01001
01110
Given the above grid map, return 2.

Here are the two distinct islands:

111
1
and

1
1
Notice that:

111
1
and

1
111
are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.

找到一个小岛之后,生成其对应8个变形(自身、翻转、旋转等)
然后返回其排序最小的那个,作为这种类型的小岛的代表
*/


class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the number of distinct islands
     */
    int numDistinctIslands2(vector<vector<int>> &grid) {
        int m=grid.size();
		if(m==0 || grid[0].size()==0){
			return 0;
		}
		int n=grid[0].size();
		set<vector<pair<int,int>>>set;
		vector<vector<bool> >vis(m, vector<bool>(n,0));

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]==1 && !vis[i][j]){
					vector<pair<int,int>>vec;
					search(grid,i,j,vis, vec);
					set.insert(normalize(vec));
				}
			}
		}
		return set.size();
    }
	void search(vector<vector<int>> &grid, int x, int y,vector<vector<bool>> &vis, vector<pair<int,int> >& vec){
		vec.push_back(make_pair(x,y));
		vis[x][y]=1;

		int m=grid.size(), n=grid[0].size();
		for(int i=0;i<4;i++){
			int dx=x+dirs[i][0];
			int dy=y+dirs[i][1];
			if(dx>=0 && dx<m && dy>=0 && dy<n && grid[dx][dy]==1 && !vis[dx][dy] ){
				search(grid,dx,dy,vis,vec);
			}
		}
	}
	vector<pair<int,int>> normalize(vector<pair<int,int>>&vec){
/*
	    cout<<"before:"<<endl;
	    for(int i=0;i<vec.size();i++){
            cout<<vec[i].first<<"  "<<vec[i].second<<endl;
	    }
	    cout<<endl;
*/

		vector<vector<pair<int,int>>>res;
		for(int i=0;i<4;i++){
			vector<pair<int,int> >v1,v2;
			for(int j=0;j<vec.size();j++){
				int x=vec[j].first;
				int y=vec[j].second;
/**
这种属于枚举了所有的形状貌似(组合之后的所有形状)
(1,1)
(x,y)对应的是不变的情况,即自身
(y,x)对应的是先向左翻转在旋转90度
(1,-1)
(x,y)对应的是往下翻转
(y,x)对应的是顺时针旋转90度
(-1,1)
(x,y)对应的是向左翻转
(y,x)对应的是顺时针旋转270度
(-1,-1)
(x,y)对应的是顺时针旋转180度
(y,x)对应的是先向左翻转在向下翻转

*/
				v1.push_back(make_pair(x*trans[i][0],y*trans[i][1]));
				v2.push_back(make_pair(y*trans[i][0],x*trans[i][1]));
			}
			res.push_back(v1);
			res.push_back(v2);
		}
		for(int i=0;i<res.size();i++){
			/**
			排完序之后在计算相对坐标,注意减第一个坐标时,要倒着减(不然第一个先变为0了,后续的没变)
			*/
            sort(res[i].begin(),res[i].end());
            for(int j=res[i].size()-1;j>=0;j--){
                res[i][j].first-=res[i][0].first;
                res[i][j].second-=res[i][0].second;
            }
		}
		/**
		之后排序,返回最小的坐标
		*/
		sort(res.begin(),res.end());
/*
        cout<<"begin:"<<endl;
		for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                cout<<res[i][j].first<<"  "<<res[i][j].second<<endl;
            }
            cout<<endl;
		}
        cout<<"end"<<endl;
*/
		return res[0];
	}

private:
	int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
	int trans[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
};

int main(){
    Solution s;
    vector<vector<int>> grid;
    grid.push_back(vector<int>{1,1,0,0,0});
    grid.push_back(vector<int>{1,0,0,0,0});
    grid.push_back(vector<int>{0,0,0,0,1});
    grid.push_back(vector<int>{0,0,0,1,1});
    cout<<s.numDistinctIslands2(grid)<<endl;
}
